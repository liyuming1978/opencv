#include <iostream>
#include <opencv2/dnn.hpp>

using namespace cv;
using namespace cv::dnn;

int main(int argc, char **argv)
{
	if(argc<3){
		std::cout <<"call it with dump path + caffe(.prototxt+.caffemodel) , or tensorflow(.pb + .txt) , or torch(.dat,.txt)\n";
		std::cout <<"for ex: dumpnet ~/dumppath resnet.prototxt resnet.caffemodel\n";
	}
	Net net;
	String dumppath = argv[1];
	String name1 = argv[2];
	String name2;
	if(argc>=4)
		name2 = argv[3];

	String suffixStr = name1.substr(name1.find_last_of('.') + 1);
	std::cout << suffixStr;
	if(suffixStr.compare("prototxt")==0 && argc>=3){
		net = readNetFromCaffe(name1, name2);	
	}else if(suffixStr.compare("pb")==0 ){
		net = readNetFromTensorflow(name1, name2);	
	}else if(suffixStr.compare("dat")==0 ){
		net = readNetFromTorch(name1, true);	
	}else if(suffixStr.compare("txt")==0 ){
		net = readNetFromTorch(name1, false);	
	}else
		std::cout <<"only support .prototxt , .pb. .dat ,.txt\n";

	net.dumpXml(dumppath);
	return 0;
}
