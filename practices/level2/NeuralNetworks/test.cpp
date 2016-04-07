#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "ann/ann.hpp"

/*

测试一个数大于还是小于10

*/

using namespace std;
const int trainNumber = 10000000;
int main(){
	ANN ann(3,10,1,0.03);
	double loss = 0.0;
	for(int i = 1; i < trainNumber; ++i){
		vector<double> data(3),ans(1);
		data[0] = 1.0*rand()/RAND_MAX < 0.5 ? 0 : 1;
		data[1] = 1.0*rand()/RAND_MAX < 0.5 ? 0 : 1;
		data[2] = 1.0*rand()/RAND_MAX < 0.5 ? 0 : 1;
		ans[0] = 1.0*(data[0]*4 + data[1]*2 + data[2])/8;
		double er = ann.train(data,ans);
		const double m = 0.9;
		loss = m * loss + (1.0 - m) * er;
		if( i % 10000 == 0 ) {
			//printf("test %1f%1f%1f = %1f\n",data[0],data[1],data[2],ans[0]);
			printf("%d :: er = %.5f loss = %.5f\n", i, er, loss);
		}
	}
	cout << "Please Input Number" << endl;
	while(1){
		int d,d2,d3;
		cin >> d >> d2 >> d3;
		vector<double> a(3);
		a[0] = d; a[1] = d2; a[2] = d3;
		ann.setInput(a);
		vector<double> ans = ann.getOutput();
		cout <<  ans[0]*8 << endl;
	}
	return 0;
}