#include "iostream"
#include <thread>
#include <chrono>

#include "grpcpp/grpcpp.h"
#include "simple_hello.grpc.pb.h"
#include "healthCheck.grpc.pb.h"

using namespace std;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

// using grpc::health::v1::Health;
using simple::HealthCheckRequest;
using simple::HealthCheckResponse;

using simple::Request;
using simple::RequestService;
using simple::Response;

using grpc::health::v1::Health;

void handleServerHealthCheckStatus_V2(const grpc::health::v1::HealthCheckResponse &healthResponse)
{
    if (healthResponse.status() == grpc::health::v1::HealthCheckResponse_ServingStatus_SERVING)
    {
        std::cout << " health check Status SERVING " << std::endl;
    }
    else
    {
        std::cout << " health check Status NOT_SERVING " << std::endl;
    }
}
void handleServerHealthCheckStatus_V1(const HealthCheckResponse &healthResponse)
{
    if (healthResponse.status() == simple::HealthCheckResponse_ServingStatus_SERVING)
    {
        std::cout << " health check Status SERVING " << std::endl;
    }
    else
    {
        std::cout << " health check Status NOT_SERVING " << std::endl;
    }
}
bool handleStatsFromServer(const Status &status)
{

    if (status.ok())
    {
        std::cout << "Status OK " << std::endl;
        return true;
    }
    else if (status.error_code() == grpc::StatusCode::DEADLINE_EXCEEDED)
    {
        std::cout << "STATUS error code= " << status.error_code() << ": error message = " << status.error_message() << std::endl;
    }
    else
    {
        std::cout << "STATUS error code= " << status.error_code() << ": error message = " << status.error_message() << std::endl;
    }
    return false;
}
void healthCheckProbe_V2(const std::string iConnectionString)
{
    std::shared_ptr<Channel> channel_sptr = grpc::CreateChannel(iConnectionString, grpc::InsecureChannelCredentials());
    std::unique_ptr<grpc::health::v1::Health::Stub> client_uptr = grpc::health::v1::Health::NewStub(channel_sptr);

    ClientContext client_context;
    grpc::health::v1::HealthCheckRequest helathRequest;
    grpc::health::v1::HealthCheckResponse healthResponse;

    helathRequest.set_service("rService");
    Status status = client_uptr->Check(&client_context, helathRequest, &healthResponse);
    if (handleStatsFromServer(status))
    {
        handleServerHealthCheckStatus_V2(healthResponse);
    }
}
void healthCheckProbe_V1(const std::string iConnectionString)
{
    std::shared_ptr<Channel> channel_sptr = grpc::CreateChannel(iConnectionString, grpc::InsecureChannelCredentials());
    std::unique_ptr<RequestService::Stub> client_uptr = RequestService::NewStub(channel_sptr);

    ClientContext client_context;
    HealthCheckRequest helathRequest;
    HealthCheckResponse healthResponse;

    helathRequest.set_service("rService");
    Status status = client_uptr->Check(&client_context, helathRequest, &healthResponse);
    if (handleStatsFromServer(status))
    {
        handleServerHealthCheckStatus_V1(healthResponse);
    }
}
void runClient(const std::string iConnectionString)
{

    std::shared_ptr<Channel> channel_sptr = grpc::CreateChannel(iConnectionString, grpc::InsecureChannelCredentials());
    std::unique_ptr<RequestService::Stub> client_uptr = RequestService::NewStub(channel_sptr);
    Request request;
    Response response;
    ClientContext client_context;

    // Set DeadLine
    const std::chrono::time_point deadline = std::chrono::system_clock::now() +
                                             std::chrono::milliseconds(10000);
    client_context.set_deadline(deadline);

    // Set Metadata
    // client_context.AddMetadata("UUIDXXXX", "1234-VXYZ-0987-QWER");
    // client_context.AddMetadata("UUIDXXXX", "testvalue");
    // client_context.AddMetadata("uuidxxxx", "testvalue");
    // client_context.AddMetadata("Uuidxxxx", "1234-VXYZ-0987-QWER");
    client_context.AddMetadata("uuidxxxxxxxxxxxxxxxxxxxxxxxxx", "1234-VXYZ-0987-QWER-XXXX-XXXX-XXXX-XXXX-XXXX-XXXX");
    client_context.AddMetadata("testkey", "testvalue");

    std::cout << "Sending request: \"" << request.ShortDebugString() << "\"\n";

    request.set_query("Hello");
    std::cout << "peer before calling server " << client_context.peer() << std::endl;

    // Check Server Health
    healthCheckProbe_V1(iConnectionString);
    healthCheckProbe_V2(iConnectionString);

    // Below service call is blocking call
    Status status = client_uptr->rService(&client_context, request, &response);
    std::cout << "peer After calling server " << client_context.peer() << std::endl;

    if (status.ok())
    {
        std::cout << " Reply from server =" << response.response() << std::endl;
    }
    else if (status.error_code() == grpc::StatusCode::DEADLINE_EXCEEDED)
    {
        std::cout << "STATUS error code= " << status.error_code() << ": error message = " << status.error_message() << std::endl;
    }
    else
    {
        std::cout << "STATUS error code= " << status.error_code() << ": error message = " << status.error_message() << std::endl;
    }
}

void singleThread(const std::string iConnectionString){
    std::thread t1(runClient, iConnectionString);
    t1.join();
}

void threadPool(const std::string iConnectionString){
    std::vector<std::thread> threadPool;
    for (int i = 0; i < 100; i++)
    {
        threadPool.emplace_back(runClient, iConnectionString);
    }
    for (int i = 0; i < 100; i++)
    {
        threadPool[i].join();
    }
}

int main()
{
    //const std::string connectionString = "localhost:4000";
    const std::string connectionString = "0.0.0.0:4000";
    

    runClient(connectionString);
    //threadPool(connectionString);


}
