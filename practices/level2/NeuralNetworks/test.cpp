#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "ann/ann.hpp"

/*

测试一个数大于还是小于10

*/

using namespace std;
const int trainNumber = 1000000;
int main(){
	ANN ann(1,100,1,0.1);
	double loss = 0.0;
	for(int i = 1; i < trainNumber; ++i){
		vector<int> data(1),ans(1);
		data[0] = 1.0*rand()/RAND_MAX*(20);
		ans[0] = data[0] < 10 ? 0 : 1;
		double er = ann.train(data,ans);
		const double m = 0.9;
		loss = m * loss + (1.0 - m) * er;
		if( i % 10000 == 0 ) {
			printf("%d :: er = %.5f loss = %.5f\n", i, er, loss);
		}
	}
	cout << "Please Input Number" << endl;
	while(1){
		int d;
		cin >> d;
		vector<int> a(1);
		a[0] = d;
		ann.setInput(a);
		vector<int> ans = ann.getOutput();
		cout << (ans[0] ? " max ":" min ") << endl;
	}
	return 0;
}