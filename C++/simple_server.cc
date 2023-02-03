#include "iostream"
#include <thread>
#include <chrono>

#include "grpcpp/grpcpp.h"
#include "simple_hello.grpc.pb.h"
#include "simple_hello.pb.h"
#include "healthCheck.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using simple::HealthCheckRequest;
using simple::HealthCheckResponse;
using simple::Request;
using simple::RequestService;
using simple::Response;

using grpc::health::v1::Health;

using namespace std;
#include <chrono>
#include <thread>

std::atomic<int> clientServedCountGlobalAtomicVar = 0;
std::atomic<int> clientServervingCountGlobalAtomicVar = 0;

class HealthServiceImpl final : public grpc::health::v1::Health::Service
{

public:
    void set_status(const grpc::health::v1::HealthCheckResponse::ServingStatus iStatus)
    {
        status = iStatus;
    }

private:
    Status Check(ServerContext *context,
                 const grpc::health::v1::HealthCheckRequest *request,
                 grpc::health::v1::HealthCheckResponse *reply) override
    {

        std::cout << "Query = " << request->service() << std::endl;
        reply->set_status(status);
        return Status::OK;
    }
    grpc::health::v1::HealthCheckResponse::ServingStatus status = grpc::health::v1::HealthCheckResponse_ServingStatus_SERVICE_UNKNOWN;
};

class RequestServiceImpl final : public RequestService::Service
{

    Status Check(ServerContext *context,
                 const HealthCheckRequest *request,
                 HealthCheckResponse *reply) override
    {
        reply->set_status(simple::HealthCheckResponse_ServingStatus_SERVING);
        return Status::OK;
    }
    void findCompressionAlgoritham(
        const grpc_compression_algorithm compressionAlgoritham)
    {

        switch (compressionAlgoritham)
        {

        case GRPC_COMPRESS_NONE:
            std::cout << "compression_algo GRPC_COMPRESS_NONE" << std::endl;
            break;
        case GRPC_COMPRESS_DEFLATE:
            std::cout << "compression_algo GRPC_COMPRESS_DEFLATE" << std::endl;
            break;
        case GRPC_COMPRESS_GZIP:
            std::cout << "compression_algo GRPC_COMPRESS_GZIP" << std::endl;
            break;
        case GRPC_COMPRESS_ALGORITHMS_COUNT:
            std::cout << "compression_algo GRPC_COMPRESS_ALGORITHMS_COUNT" << std::endl;
        case GRPC_COMPRESS_STREAM_GZIP:
            std::cout << "compression_algo GRPC_COMPRESS_STREAM_GZIP" << std::endl;
            break;
        }
    }
    Status rService(ServerContext *context,
                    const Request *request,
                    Response *reply) override
    {
        std::string prefix("Hello ");
        clientServervingCountGlobalAtomicVar++;
        clientServeringCount = clientServeringCount + 1;

        std::cout << "peer " << context->peer() << std::endl;
        std::chrono::system_clock::time_point deadline = context->deadline();
        auto compression_algo = context->compression_algorithm();
        findCompressionAlgoritham(compression_algo);
        // client_metadata is the one of the way to communicate b/w client and server
        auto clientMetaData = context->client_metadata();
        std::cout << "simple Server rService " << clientMetaData.size() << std::endl;
        for (auto [key, value] : clientMetaData)
        {
            std::cout << "Client Meta data = " << key << " -> " << value << std::endl;
        }
        if (clientServedCountGlobalAtomicVar % 2 == 0)
        {
            std::chrono::milliseconds timespan(9999); // 9 second
            std::this_thread::sleep_for(timespan);
        }

        clientServedCountGlobalAtomicVar++;
        prefix = "Hello " + std::to_string(clientServedCountGlobalAtomicVar) + "Active serve " + std::to_string(clientServervingCountGlobalAtomicVar) + " " + std::to_string(clientServeringCount) + " ";

        clientServervingCountGlobalAtomicVar--;
        clientServeringCount = clientServeringCount - 1;
        if (context->IsCancelled())
        {
            std::cout << "Deadline reached" << std::endl;
            return Status(grpc::StatusCode::CANCELLED, "Deadline exceeded or Client cancelled, abandoning.");
        }
        reply->set_response(prefix + request->query() + " " + std::to_string(clientServervingCountGlobalAtomicVar) + " " + std::to_string(clientServeringCount));

        return Status::OK;
    }

private:
    static int clientServeringCount;
};

int RequestServiceImpl::clientServeringCount = 0;

/*
    Grpc HealthCheck:
    This thread will check grpc health status in every 9 second.
    Current implementation is developed to simuate the
    health check behaviour
*/
void helathCheck(HealthServiceImpl *rHealth)
{
    std::chrono::milliseconds timespan(9999); // 9 second
    while (true)
    {

        std::this_thread::sleep_for(timespan);
        long int t = static_cast<long int>(time(NULL)); // Get current time in log int format
        t = t / 10;
        //  auto nanos = duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        if (t % 2 == 0)
        {
            std::cout << "Health check thread HealthCheckResponse_ServingStatus_NOT_SERVING" << t << std::endl;
            rHealth->set_status(grpc::health::v1::HealthCheckResponse_ServingStatus_NOT_SERVING);
        }
        else
        {
            std::cout << "Health check thread HealthCheckResponse_ServingStatus_SERVICE" << t << std::endl;
            rHealth->set_status(grpc::health::v1::HealthCheckResponse_ServingStatus_SERVING);
        }
    }
}
int main()
{

    ServerBuilder builder;
    // Service implementation
    RequestServiceImpl rService;
    HealthServiceImpl rHealth;
    // Service Registration
    builder.RegisterService(&rService);
    builder.RegisterService(&rHealth);

    // Helath Check thread Wait
    std::thread healthCheck(helathCheck, &rHealth);
    // Server operation
    // 1: Build
    // 2: Start
    // 3: Wait
    builder.AddListeningPort("localhost:4000", grpc::InsecureServerCredentials());
    std::unique_ptr<Server> server(builder.BuildAndStart());
    server->Wait();
}