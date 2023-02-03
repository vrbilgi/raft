

Just execute the following commands:

Run the server:
```
$ cd server 
$ docker build . -t grpc-demo/server
$ docker run --net=host -it grpc-demo/server 
```


Run the client:
```
$ cd client 
$ docker build . -t grpc-demo/client
$ docker run --net=host -it grpc-demo/client 
```

