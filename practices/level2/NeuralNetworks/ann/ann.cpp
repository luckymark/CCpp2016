#include <cmath>
#include <cstdlib>
#include <assert.h>
#include "ann.hpp"

//#define DEBUG 

void ANN::spread(std::vector<double> &data){
	assert(data.size() == inputLayerSize);
	for(int i = 0; i < inputLayerSize; ++i)
		inputLayer[i].output = data[i]; //输入一组学习数据
	for(int i = 0; i < hiddenLayerSize; ++i)
		hiddenLayer[i].output = 0;
	for(int i = 0; i < outputLayerSize; ++i)
		outputLayer[i].output = 0;
	//清空当前网络输出初始值
	for(int i = 0; i < hiddenLayerSize; ++i)
		for(int j = 0; j < inputLayerSize; ++j){
			hiddenLayer[i].output += inputLayer[j].output * inputLayer[j].w[i];
			hiddenLayer[i].output = f(hiddenLayer[i].output - hiddenLayer[i].threshold);
		}
	//输入层传播至隐藏层

	for(int i = 0; i < outputLayerSize; ++i)
		for(int j = 0; j < hiddenLayerSize; ++j){
			outputLayer[i].output += hiddenLayer[j].output * hiddenLayer[j].w[i];
			outputLayer[i].output = f(outputLayer[i].output - outputLayer[i].threshold);
		}
	//隐藏层传播至输出层

}

void ANN::countXita(std::vector<double> &g,std::vector<double> &e,std::vector<double> &ans){
	assert(g.size() == outputLayerSize);
	assert(e.size() == hiddenLayerSize);
	assert(ans.size() == outputLayerSize);
	for(int i = 0; i < outputLayerSize; ++i){
		double op = outputLayer[i].output;
		g[i] = op * (1 - op) * (ans[i] - op); //输出层梯度项
	}
	for(int i = 0; i < hiddenLayerSize; ++i){
		double op = hiddenLayer[i].output ,sigma = 0;
		for(int j = 0; j < outputLayerSize; ++j)
			sigma += g[j] * hiddenLayer[i].w[j];
		e[i] = op * (1 - op) * sigma; //隐藏层梯度项
	}
}

void ANN::bp(std::vector<double> &g,std::vector<double> &e){
	for(int i = 0; i < outputLayerSize; ++i){
		outputLayer[i].threshold -= learningrate * g[i]; //更新输出层阈值
	}
	for(int i = 0; i < hiddenLayerSize; ++i){
		hiddenLayer[i].threshold -= learningrate * e[i]; //更新隐藏层阈值
		for(int j = 0; j < outputLayerSize; ++j)
			hiddenLayer[i].w[j] += learningrate * g[j] * hiddenLayer[i].output; //更新隐藏层权值
	}
	for(int i = 0; i < inputLayerSize; ++i){
		for(int j = 0; j < hiddenLayerSize; ++j)
			inputLayer[i].w[j] += learningrate * e[j] * inputLayer[i].output; //更新输入层权值
	}
}

double ANN::train(std::vector<std::vector<double> > &data,std::vector<std::vector<double> > &ans){
	assert(data.size() == ans.size());
	assert(data.size() >= 1);
	int dataCase = data.size();
	std::vector<double> sigmaG(outputLayerSize,0),sigmaE(hiddenLayerSize,0),g(outputLayerSize),e(hiddenLayerSize);
	for(int cas = 0; cas < dataCase; ++cas){
		spread(data[cas]);
		countXita(g,e,ans[cas]);
		for(int i = 0; i < outputLayerSize; ++i)
			sigmaG[i] += g[i];
		for(int i = 0; i < hiddenLayerSize; ++i)
			sigmaE[i] += e[i];
	}

	for(int i = 0; i < outputLayerSize; ++i)
		sigmaG[i] /= dataCase;
	for(int i = 0; i < hiddenLayerSize; ++i)
		sigmaE[i] /= dataCase;
	//统计偏差量平均值

	bp(sigmaG,sigmaE);

	//计算累计误差
	double E = 0;
	for(int i = 0; i < outputLayerSize; ++i){
		E += (outputLayer[i].output - ans[0][i]) * (outputLayer[i].output - ans[0][i]);
	}
	return E / outputLayerSize;
}

void ANN::setInput(std::vector<double> &data){
	spread(data);
}

std::vector<double> ANN::getOutput(){
	std::vector<double> ret(outputLayerSize);
	for(int i = 0; i < outputLayerSize; ++i){
		ret[i] = outputLayer[i].output > 0.5 ? 1 : 0;
	}
	return ret;
}