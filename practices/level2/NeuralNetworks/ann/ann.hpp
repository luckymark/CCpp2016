#ifndef _ANN_HPP
#define _ANN_HPP

/*
BY tsstss123
2016-04-03
*/

#include <vector>
#include <cstdlib>
#include <cmath>

struct MPNode{
	double threshold; //阈值
	double output; //输出值
	std::vector<double> w; //连接权值
	void init(int nextLayerSize){
		threshold = 1.0*rand()/RAND_MAX;
		//threshold = 0;
		output = 0;
		w.resize(nextLayerSize);
		for(int i = 0; i < nextLayerSize; ++i)
			w[i] = 1.0*rand()/RAND_MAX;
	}
};

class ANN{
	//ANN Use BP Alogirthm
public:
	int inputLayerSize,hiddenLayerSize,outputLayerSize;
	double learningrate;
	std::vector<MPNode> inputLayer,hiddenLayer,outputLayer;

	double train(std::vector<std::vector<double> > &data,std::vector<std::vector<double> > &ans);
	void setInput(std::vector<double> &data);
	std::vector<double> getOutput();
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
	double sigmoid(double x){
		return 1.0/(1.0+exp(-x));
	}
private:
	double f(double x){
		return sigmoid(x);
	}
	//使用sigmoid作为激活函数


	void countXita(std::vector<double> &g,std::vector<double> &e,std::vector<double> &ans); //计算一组偏移量 
	void spread(std::vector<double> &data); //正向传播
	void bp(std::vector<double> &g,std::vector<double> &e); //反向更新

};
#endif