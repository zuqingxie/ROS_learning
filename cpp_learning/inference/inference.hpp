#pragma once
#ifndef Inference_HPP_
#define Inference_HPP_

#include <falkolib/Feature/FALKO.h>
#include <falkolib/Common/LaserScan.h>
#include <flirtlib/geometry/point.h>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_smallint.hpp>
#include <thread>
#include <mutex> 




#include <cuda_runtime_api.h>
// #include <opencv2/opencv.hpp>
#include "NvInfer.h"
#include "NvInferPlugin.h"
#include "NvInferRuntimeCommon.h"
#include "NvOnnxParser.h"
// #include "dataType.h"
// #include "model.h"
// #include "tracker.h"//
// #include "BYTETracker.h" 
// #include <opencv2/imgproc.hpp>
// #include <opencv2/dnn.hpp>
#include <math.h>
#include <array>
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <cstdlib> //work with string work
#include <cstring> //work with string work
#include <cstdio>  //work with move file
#include <stdexcept>
#include <limits>
// #include "FeatureTensor.h"




using nvinfer1::Dims2;
using nvinfer1::Dims3;
using nvinfer1::IBuilder;
using nvinfer1::IBuilderConfig;
using nvinfer1::ICudaEngine;
using nvinfer1::IExecutionContext;
using nvinfer1::IHostMemory;
using nvinfer1::ILogger;
using nvinfer1::INetworkDefinition;
using Severity = nvinfer1::ILogger::Severity;

// using cv::Mat;
using std::array;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;
using std::vector;
using std::exception;

using namespace std::chrono; 
// using namespace cv;

typedef unsigned char uint8;

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


class Inferencer{


public:
    Inferencer();
    void Infer(const std::vector<double> input,std::vector<double> &results);
private:

    nvinfer1::IRuntime *runtime = nullptr;
    nvinfer1::ICudaEngine *engine = nullptr;
    nvinfer1::IExecutionContext *context = nullptr;
    cudaStream_t stream = nullptr;
    Logger gLogger;
    int iH, iW, in_size, out_size, out_size2, out_size3, out_size4, out_size5, out_size6 ;
    void *buffs[1];
};


#endif