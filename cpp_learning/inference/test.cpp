
#include "NvInfer.h"
#include "NvInferPlugin.h"
#include "NvInferRuntimeCommon.h"
#include <cuda_runtime_api.h>
#include <iostream>

#include <filesystem>
#include <fstream>
#include <vector>
using namespace nvinfer1;
using Severity = nvinfer1::ILogger::Severity;

class Logger : public ILogger
{
public:
    void log(Severity severity, const char *msg) noexcept override
    {
        if (severity != Severity::kINFO)
        {
            std::cout << msg << std::endl<<" ";
        }
    }
};


int main(){


	nvinfer1::IRuntime *runtime = nullptr;
    nvinfer1::ICudaEngine *engine = nullptr;
    nvinfer1::IExecutionContext *context = nullptr;
    cudaStream_t stream = nullptr;
    Logger gLogger;
    int iH, iW, in_size, out_size, out_size2, out_size3, out_size4, out_size5, out_size6 ;
    void *buffs[1];

	std::string model_path = "/home/zuqing/Documents/Git/MA_workspace/MA_DL_approach/model_test_batched_64.engine";
    std::ifstream ifile(model_path, std::ios::in | std::ios::binary);


    ifile.seekg(0, std::ios::end);
    // 文件的大小 mdsize
    const int mdsize = ifile.tellg();
    ifile.clear();
    ifile.seekg(0, std::ios::beg);

    std::vector<char> buf(mdsize);
    ifile.read(&buf[0], mdsize);
    ifile.close();
	// IRuntime* runtime = createInferRuntime(logger);

    runtime = createInferRuntime(gLogger);
    engine = runtime->deserializeCudaEngine((void *)&buf[0], mdsize, nullptr);
    auto in_dims = engine->getBindingDimensions(engine->getBindingIndex("conv1d_input"));

};