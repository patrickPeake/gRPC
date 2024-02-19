#include <grpcpp/grpcpp.h>

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "result.h"
#include "register_client.h"

int main(int argc, char** argv) {
    std::string address("localhost:50051");
    RegisterServiceClient client(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()),
                                 std::cout);
    // This is a sample client
    client.CreateRegisterArray("test", 4);
    client.CreateRegisterArray("test", 4);
    client.CreateRegisterArray("test1", 5);
    client.ReadValue("test", 0);
    client.ReadValue("test", 1);
    client.ReadValue("test1", 1);

    printf("\n\n");
    client.WriteValue("test", 0, 100);
    client.WriteValue("test", 0, 200);
    client.WriteValue("test", 1, 2);
    client.WriteValue("test", 1, 3);
    client.WriteValue("test1", 1, 3);
    client.WriteValue("test", 100, 3);
    
    printf("\n\n");
    client.CreateRegisterArray("flowCount", 4);
    client.WriteValue("flowCount", 2, 100);
    client.ReadValue("flowCount", 0);
    client.ReadValue("flowCount", 2);
    client.ReadValue("flowCount", 5);

    printf("\n\n");
    client.ReadValue("test", 0);
    client.ReadValue("test", 1);
    client.GetAllRegisterArrays();
    
    printf("\n\n");
    Result* r = client.GetRegisterArray("test1");
    client.DeleteRegisterArray("test1");
    client.GetRegisterArray("test1");

    return 0;
}
