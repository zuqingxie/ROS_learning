
#include "inference.hpp"

std::vector<double> Inputdata1 = {
		6.8310093879699707,
		0.96100896596908569,
		0.95900893211364746,
		0.95900893211364746,
		0.95200890302658081,
		0.9480089545249939,
		0.9430088996887207,
		0.94000887870788574,
		0.93700885772705078,
		0.93300884962081909,
		0.9290088415145874,
		0.92600888013839722,
		0.92300879955291748,
		0.91900879144668579,
		0.91700881719589233,
		0.91300880908966064,
		0.91000872850418091,
		0.90700876712799072,
		0.90300875902175903,
		0.90000873804092407,
		0.89700865745544434,
		0.89400869607925415,
		0.89100867509841919,
		0.8870086669921875,
		0.88400870561599731,
		0.88100862503051758,
		0.87800860404968262,
		0.87600862979888916,
		0.8730086088180542,
		0.87100857496261597,
		0.87000858783721924,
		0.86800855398178101,
		0.86700856685638428,
		0.8670085072517395,
		0.8670085072517395,
		0.8670085072517395,
		0.8670085072517395,
		0.86900842189788818,
		0.86800843477249146,
		0.86800843477249146,
		0.86900842189788818,
		0.86900836229324341,
		0.87100839614868164,
		0.8730083703994751,
		0.87500840425491333,
		0.87800830602645874,
		0.8810083270072937,
		0.88200831413269043,
		0.88400834798812866,
		0.88700824975967407,
		0.89100825786590576,
		0.89600825309753418,
		0.90000826120376587,
		0.90400820970535278,
		0.90600818395614624,
		0.9090082049369812,
		0.91100823879241943,
		0.91100817918777466,
		0.91000813245773315,
		0.90900814533233643,
		3.5710082054138184,
		3.5600082874298096,
		3.5550081729888916,
		3.5500082969665527
};
std::vector<double> Inputdata2 = {
	1.1850078105926514,
		1.1790077686309814,
		1.1750078201293945,
		1.1710077524185181,
		1.1690077781677246,
		1.1650077104568481,
		1.1610076427459717,
		1.1580077409744263,
		1.1550077199935913,
		1.1530076265335083,
		1.1520076990127563,
		1.1490076780319214,
		1.1450076103210449,
		1.1410075426101685,
		1.139007568359375,
		1.1370075941085815,
		1.13600754737854,
		1.1340075731277466,
		1.1340075731277466,
		1.1310074329376221,
		1.1300073862075806,
		1.1270074844360352,
		1.1240074634552002,
		1.1210074424743652,
		1.1180074214935303,
		1.1160073280334473,
		1.1170073747634888,
		1.1180073022842407,
		1.1170073747634888,
		1.1150072813034058,
		1.1140073537826538,
		1.1130073070526123,
		1.1130071878433228,
		1.1140072345733643,
		1.1160072088241577,
		1.1200071573257446,
		1.1240072250366211,
		1.1300071477890015,
		1.1360070705413818,
		1.1420071125030518,
		1.1480070352554321,
		1.1530070304870605,
		1.1580071449279785,
		1.1630071401596069,
		1.1680071353912354,
		1.1740069389343262,
		1.1810070276260376,
		1.1890069246292114,
		1.1960070133209229,
		1.2020069360733032,
		1.2020069360733032,
		1.2080068588256836,
		1.213006854057312,
		1.2280068397521973,
		1.4770069122314453,
		1.4930068254470825,
		1.4910068511962891,
		1.4900068044662476,
		1.4880067110061646,
		1.4860067367553711,
		1.4850066900253296,
		1.4830067157745361,
		1.4790067672729492,
		1.4750065803527832
};



int main(){

	Inferencer inf;
	std::vector<double> result;
	inf.Infer(Inputdata1, result);
}


Inferencer::Inferencer()


{

    std::string model = "model_64";
    std::string model_path = "/home/zuqing/Documents/Git/MA_workspace/MA_DL_approach/model.trt";
    std::ifstream ifile(model_path, std::ios::in | std::ios::binary);

    if (!ifile)
    {
        // RCLCPP_ERROR(this->logger, "model path: %s, no model file found");
        cout<<"model path error: "<<model_path <<endl;
        //导致程序立即停止
        std::abort();
    }
    // 读取文件内容到buf里面
    // 将文件的指针放到最后
    ifile.seekg(0, std::ios::end);
    // 文件的大小 mdsize
    const int mdsize = ifile.tellg();
    ifile.clear();
    ifile.seekg(0, std::ios::beg);

    std::vector<char> buf(mdsize);
    ifile.read(&buf[0], mdsize);
    ifile.close();

    // RCLCPP_INFO(this->logger, "Model size: %d", mdsize);
        cout<<"model size:"<< mdsize <<endl;

    //建立推理对象
    // //这段代码的作用是创建了一个 TensorRT 推理运行时，初始化了 TensorRT 插件库，然后从内存中的序列化数据中重建了一个 CUDA 引擎，并获取了其中名为 "pointcloud" 的输入绑定的维度信息。
    runtime = nvinfer1::createInferRuntime(gLogger);
    // initLibNvInferPlugins(&gLogger, "");
    // engine = runtime->deserializeCudaEngine((void *)&buf[0], mdsize, nullptr);
    // auto in_dims = engine->getBindingDimensions(engine->getBindingIndex("input"));

    // //???
    // // iH = in_dims.d[2];
    // // iW = in_dims.d[3];
    // in_size = 1;
    // for (int j = 0; j < in_dims.nbDims; j++)
    // {
    //     in_size *= in_dims.d[j];
    // }
    // // RCLCPP_INFO(this->logger, "data size is %d", in_size);
	// cout<<"data size is "<<in_size<<endl;


    // auto out_dims = engine->getBindingDimensions(engine->getBindingIndex("embedding"));
    // out_size = 1;
    // for (int j = 0; j < out_dims.nbDims; j++)
    // {
    //     out_size *= out_dims.d[j];
    // }
    // // RCLCPP_INFO(this->logger, "output size: %d",out_size);
	// cout<<"doutput size is : "<<out_size<<endl;


    // context = engine->createExecutionContext();
    // if (!context)
    // {
    //     RCLCPP_INFO(this->logger, "create execution context failed");
    //     std::abort();
    // }

    // cudaError_t error_state;

    // error_state = cudaMalloc(&buffs[0], in_size * sizeof(float));
    // if (state)
    // {
    //     cout << "allocate memory failed\n";
    //     std::abort();
    // }



    // error_state = cudaStreamCreate(&stream);
    // if (state)
    // {
    //     cout << "create stream failed\n";
    //     std::abort();
    // }


}

void Inferencer::Infer(const std::vector<double> input,std::vector<double> &results){
	results.push_back(1);
}
