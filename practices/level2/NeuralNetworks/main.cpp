#include <bits/stdc++.h>
#include "ann/ann.hpp"

using namespace std;

const int DATASIZE = 3500 , TESTSIZE = 1500;
const double eps = 1e-4;

vector<double> data[DATASIZE],dataans[DATASIZE];
vector<double> test[TESTSIZE],testans[TESTSIZE];

void getData(string fileName,vector<double> data[],vector<double> ans[],int size){//训练一波
	char tmp;int bit;
	ifstream traindata;
	traindata.open(fileName.c_str());
	for(int cas = 0; cas < size; ++cas) {
		for(int i = 0; i < 64; i++){
			traindata >> bit >> tmp;
			data[cas].push_back(1.0*bit/16);
		}
		traindata >> bit;
		ans[cas].resize(10);
		for(int i = 0; i < 10; ++i)
			ans[cas][i] = (i == bit ? 1 : 0); 
	}
	traindata.close();
}
void training(ANN &ann,int datasize,double eps){
	double loss = 0;
	const double m = 0.9;
	// 统计回归效率
	int times = 0;
	do{
		double er;
		for(int i = 0; i < datasize; ++i){
			er = ann.train(data[i],dataans[i]);
			//printf("  %.6f \n",er);
			loss = m * loss + (1.0 - m) * er;
		}
		printf("Times = %d , loss = %.5f\n",++times,loss);
		int t1 = time(0);
	}while(loss > eps);
	// 精度达到要求
	printf("Training Finish!!!!\n");
	return ;
}
double testing(ANN &ann,int datasize){
	vector<double> ans(10);
	int err = 0;
	for(int cas = 0; cas < datasize; ++cas){
		ann.setInput(test[cas]);
		ann.getOutput(ans);
		double maxpro = 0;
		int num , tans;
		for(int i = 0; i < 10; ++i){
			if(ans[i] > maxpro){
				maxpro = ans[i];
				num = i;
			}
		}
		for(int i = 0; i < 10; ++i){
			if(testans[cas][i] > 0.9)
				tans = i;
		}
		if(testans[cas][num]<0.99)
			++err; //识别错误
	}
	return (datasize - err)*1.0 / datasize;
}
int main(){
	ANN ann(64,20,10,0.1); //创建神经网络
	getData("digitstra.txt",data,dataans,DATASIZE);// 读取训练数据
	getData("digitstest.txt",test,testans,TESTSIZE);// 读取测试数据
	training(ann,DATASIZE,eps);
	printf("Corret rate = %2.1f%%\n",testing(ann,TESTSIZE)*100);
	return 0;
}