#include <cmath>
#include <cstdlib>
#include <assert.h>
#include "ann.hpp"

void ANN::spread(std::vector<int> &data){
	assert(data.size() == inputLayerSize);
	for(int i = 0; i < inputLayerSize; ++i)
		inputLayer[i].output = data[i]; //输入数据
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

void ANN::bp(std::vector<int> &ans){
	assert(ans.size() == outputLayerSize);
	std::vector<double> g(outputLayerSize),e(hiddenLayerSize);
	for(int i = 0; i < outputLayerSize; ++i){
		double op = outputLayer[i].output;
		g[i] = op * (1 - op) * (ans[i] - op); //输出层梯度项
		outputLayer[i].threshold -= learningrate * g[i]; //更新输出层阈值
	}
	for(int i = 0; i < hiddenLayerSize; ++i){
		double op = hiddenLayer[i].output ,sigma = 0;
		for(int j = 0; j < outputLayerSize; ++j)
			sigma += g[j] * hiddenLayer[i].w[j];
		e[i] = op * (1 - op) * sigma; //隐藏层梯度项
	}
	for(int i = 0; i < hiddenLayerSize; ++i){
		hiddenLayer[i].threshold -= learningrate * e[i]; //更新隐藏层阈值
		for(int j = 0; j < outputLayerSize; ++j)
			hiddenLayer[i].w[j] += learningrate * g[j] * hiddenLayer[i].output; //更新隐藏层权值
	}
	for(int i = 0; i < inputLayerSize; ++i){
		for(int j = 0; j < hiddenLayerSize; ++j)
			inputLayer[i].w[j] += learningrate * e[j] * inputLayer[i].output;
	}
}

void ANN::train(std::vector<int> &data,std::vector<int> &ans){
	spread(data);
	bp(ans);
}

void ANN::setInput(std::vector<int> &data){
	spread(data);
}

std::vector<int> ANN::getOutput(){
	std::vector<int> ret(outputLayerSize);
	for(int i = 0; i < outputLayerSize; ++i){
		ret[i] = outputLayer[i].output > 0.5 ? 1 : 0;
	}
	return ret;
}