#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "ann/ann.hpp"

using namespace std;

typedef vector<double> vd;
#define pb push_back

const int trainNumber = 1000000;
int main(){
	ANN ann(2,5,1,0.3);
	double loss = 0.0;
	vector<vector<double> > data,ans;
	data.pb(vd{0,0});ans.pb(vd{0});
	data.pb(vd{1,1});ans.pb(vd{0});
	data.pb(vd{0,1});ans.pb(vd{1});
	data.pb(vd{1,0});ans.pb(vd{1});
	for(int i = 0; i < trainNumber; ++i){
		double er = ann.train(data,ans);
		const double m = 0.9;
		loss = m * loss + (1.0 - m) * er;
		if(i % 1000 == 0)
			printf("%d :: er = %.5f loss = %.5f\n", i, er, loss);
	}
	cout << "Please Input(xy)" << endl;
	while(1){
		int x,y;
		cin >> x >> y;
		vector<double> a(2);
		a[0] = x;  a[1] = y;
		ann.setInput(a);
		vector<double> ans = ann.getOutput();
		cout << ans[0] << endl;
		//cout << (ans[0] ? " max ":" min ") << endl;
	}
	return 0;
}