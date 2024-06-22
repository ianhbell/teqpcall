#define EXPORT_CODE extern "C"
#define CONVENTION
#include "teqpc.h"

#include <string>
#include <iostream>

int main(){
    for (auto i = 0; i < 1000000; ++i){
        std::string spec = R"(
            {"kind": "vdW1", "model": {"a": 1, "b": 2}}
        )";
        long long uid = 0;
        char buffer[300] = " ";
        auto errcode = build_model(spec.c_str(), &uid, buffer, 300);
        if (errcode != 0){
            std::cout << buffer << std::endl;
            return EXIT_FAILURE;
        }
        if (i % 100000 == 0){
            std::cout << uid << std::endl;
        }
        
    }
}
