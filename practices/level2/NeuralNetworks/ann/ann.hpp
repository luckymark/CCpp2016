#ifndef _ANN_HPP
#define _ANN_HPP

/*
BY tsstss123
2016-04-03
*/

#include <vector>
#include <cstdlib>

struct MPNode{
	double threshold; //阈值
	double output; //输出值
	std::vector<double> w; //连接权值
	void init(int nextLayerSize){
		threshold = random();
		output = 0;
		w.resize(nextLayerSize);
	}
};

class ANN{
	//ANN Use BP Alogirthm
public:
	int inputLayerSize,hiddenLayerSize,outputLayerSize;
	double learningrate;
	std::vector<MPNode> inputLayer,hiddenLayer,outputLayer;

	void train(std::vector<int> &data,std::vector<int> &ans);
	void setInput(std::vector<int> &data);
	std::vector<int> getOutput();
	ANN(int is,int hs,int os,double rate){
		srand(is*hs*os+1);
		//初始化随机数
		learningrate = rate;
		inputLayerSize = is;
		hiddenLayerSize = hs;
		outputLayerSize = os;
		inputLayer.resize(is);
		hiddenLayer.resize(hs);
		outputLayer.resize(os);
		for(int i = 0; i < is; ++i){
			inputLayer[i].init(hs);
		}
		for(int i = 0; i < hs; ++i){
			hiddenLayer[i].init(os);
		}
		for(int i = 0; i < os; ++i){
			outputLayer[i].init(0);
		}
	}
private:
	double sigmoid(double x){
		return 1.0/(1.0+std::exp(-x));
	}
	double f(double x){
		return f(sigmoid(x));
	}
	//使用sigmoid作为激活函数
	double random(){
		return 1.0*rand()/RAND_MAX;
	}
	//生成(0,1)的随机数

	void initMPNode(MPNode &nd,int nextLayerSize);
	void spread(std::vector<int> &data);
	void bp(std::vector<int> &ans);

};
#endif