import sys
import time
import json
import _thread
import threading
import socket
# import thread
from multiprocessing import Process
import random
import pickle

from KThread import *
from messages import *
from follower_functions import *


class Server(object):
	def __init__(self, id_,time,name):
		self.name=name
		self.time = time
		self.id = id_
		self.config_file = 'config-%d' % self.id
		print(self.name,self.config_file)

		#self.load()
		self.role = 'follower'
		self.commitIndex = 0
		self.lastApplied = 0

		self.leaderID = 0


		with open('config.json', 'r') as f:
			address = json.load(f)
			port_list = address['AddressBook']
			running = address['running']
			self.initial_state = address['initial_state']

		self.addressbook = {}
		for id_ in running:
			print(self.name,"id_",id_)
			print(self.name,"port_list",port_list[id_ - 1])
			self.addressbook[id_] = port_list[id_ - 1]

		# need to put it into file later on
		self.load()


		self.port = self.addressbook[self.id]

		# self.nextIndex = {}
 	# 	self.matchIndex = {}
 	# 	for peer in self.peers:
 	# 		self.nextIndex[peer] = len(self.log) + 1
 	# 		self.matchIndex[peer] = 0

		self.request_votes = self.peers[:]
		print(self.name,"self.request_votes",str(self.request_votes))
		self.numVotes = 0
		self.oldVotes = 0
		self.newVotes = 0

		self.lastLogIndex = 0
		self.lastLogTerm = 0

		self.listener = KThread(target = self.listen, args= (acceptor,))
		self.listener.start()

		self.during_change = 0
		self.newPeers = []
		self.new = None
		self.old = None

	def listen(self, on_accept):
		srv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		srv.bind(("localhost", self.port))
		print (self.name,'start listenning port',str(self.port))
		while True:
			print (self.name,'Waiting for message')
			data, addr = srv.recvfrom(1024)
			thr = KThread(target=on_accept, args=(self, data, addr))
			thr.start()
			print (self.name,'Waiting for message--')
		srv.close()

	def follower(self):
		print (self.name, 'Running as a follower')
		self.role = 'follower'
		self.last_update = time.time()
		election_timeout = 5 * self.time + 5
		print(self.name,"election_timeout",election_timeout,)
		while time.time() - self.last_update <= election_timeout:
			pass
		self.start_election()
		while True:
			self.last_update = time.time()
			election_timeout = 5 * random.random() + 5
			while time.time() - self.last_update <= election_timeout:
				pass

			if self.election.is_alive():
				self.election.kill()
			self.start_election()

	def start_election(self):
		self.role = 'candidate'
		self.election = KThread(target =self.thread_election,args = ())
		print(self.name,"start_electionXXXXX")
		if len(self.peers) != 0:
			self.currentTerm += 1
			self.votedFor = self.id
			self.save()
			self.numVotes = 1
			if self.during_change == 1:
				self.newVotes = 0
				self.oldVotes = 0
				if self.id in self.new:
					self.newVotes = 1
				if self.id in self.old:
					self.oldVotes = 1
			elif self.during_change == 2:
				self.newVotes = 0
				if self.id in self.new:
					self.newVotes = 1
			self.election.start()

	def thread_election(self):
		print (self.name, 'timouts, start a new election with term %d' % self.currentTerm)
		self.role = 'candidate'
		self.request_votes = self.peers[:]
		sender = self.id

		while 1:
			# print 'Send vote request to ', self.request_votes
			for peer in self.peers:
				if peer in self.request_votes:
					Msg = str(self.lastLogTerm) + ' ' + str(self.lastLogIndex)
					msg = RequestVoteMsg(sender, peer, self.currentTerm, Msg)
					data = pickle.dumps(msg)
					sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
					print(self.name,"I have ",str(peer)," peers")
					print(self.name,"My message ",str(Msg))
					print(self.name,"I am sending data to port =",str(self.addressbook[peer]))
					sock.sendto(data, ("localhost", self.addressbook[peer]))
			time.sleep(10) # wait for servers to receive

	def leader(self):
		print (self.name,'Running as a leader')
		self.role = 'leader'
		self.nextIndex = {}
		self.matchIndex = {}
		for peer in self.peers:
			self.nextIndex[peer] = len(self.log) + 1
			self.matchIndex[peer] = 0
		self.append_entries()

	def append_entries(self):
		print (self.name,str(threading.get_ident()),'append enteries')
		receipts = self.peers[:]
		while 1:
			receipts = self.peers[:]
			if self.during_change != 0:
				for peer in receipts:
					if peer not in self.nextIndex:
						self.nextIndex[peer] = len(self.log) + 1
						self.matchIndex[peer] = 0
			for peer in receipts:
				if len(self.log) >= self.nextIndex[peer]:
					prevLogIndex = self.nextIndex[peer] - 1
					if prevLogIndex != 0:
						prevLogTerm = self.log[prevLogIndex-1].term
					else:
						prevLogTerm = 0
					entries = [self.log[self.nextIndex[peer]-1]]
				else:
					entries = []
					prevLogIndex = len(self.log)
					if prevLogIndex != 0:
						prevLogTerm = self.log[prevLogIndex-1].term
					else:
						prevLogTerm = 0

				Msg = AppendEntriesMsg(self.id, peer, self.currentTerm, entries, self.commitIndex, prevLogIndex, prevLogTerm)
				data = pickle.dumps(Msg)
				sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
				print (self.name,str(threading.get_ident()),'send append enteries to',str(self.addressbook[peer]))
				try:
					sock.sendto(data, ("localhost", self.addressbook[peer]))
				except Exception as e:
					print (self.name,str(threading.get_ident()),'send append enteries to fail XXXXXXXXXXX')
			time.sleep(10.5)

	def step_down(self):
		if self.role == 'candidate':
			print (self.name,'candidate step down when higher term')
			self.election.kill()
			self.last_update = time.time()
			self.role = 'follower'
		elif self.role == 'leader':
			self.leader_state.kill()
			self.follower_state = KThread(target = self.follower, args = ())
			self.follower_state.start()

	def load(self):
		initial_running =  [1, 2]
		# new_quorom = []

		try:
			with open(self.config_file) as f:
				serverConfig = pickle.load(f)
		except Exception as e:
			print(self.name,"Exceptoin loading pickel file",str(self.config_file))
			if self.id not in initial_running:
				print(self.name,"Exception if")
				serverConfig = ServerConfig(100, 0, -1, [], [])
			else:
				print(self.name,"Exception else",self.id )
				initial_running.remove(self.id)
				serverConfig = ServerConfig(100, 0, -1, [], initial_running)

		self.poolsize = serverConfig.poolsize
		self.currentTerm = serverConfig.currentTerm
		self.votedFor = serverConfig.votedFor
		self.log = serverConfig.log
		self.peers = serverConfig.peers
		self.majority = (len(self.peers) + 1)/2 + 1
		# self.new_quorom = new_quorom
		#self.majority_1 = (len(self.new_quorom) + 1)/2 + 1

	def save(self):
		serverConfig = ServerConfig(self.poolsize, self.currentTerm, self.votedFor, self.log, self.peers)
		print(self.name,"self.config_file",self.config_file)
		try:
			with open(self.config_file, 'wb') as f:
				pickle.dump(serverConfig, f)
		except Exception as e:
			print(self.name,'Issue in saving the file', self.config_file)
		print(self.name,"SAVE self.config_file",self.config_file)
	def run(self):
		print(self.name,"RUN")
		time.sleep(1)
		print(self.name,"START Thread")
		self.follower_state = KThread(target = self.follower, args = ())
		self.follower_state.start()
		print(self.name,"Will run as follower")
		while self.role != 'leader':
			pass
		print(self.name,"Now I am leader")
		if self.follower_state.is_alive():
			self.follower_state.kill()
		if self.listener.is_alive():
			self.listener.kill()

		print (self.name,'Now I am the leader for term %d' % self.currentTerm)
		self.leader_state.start()
			


