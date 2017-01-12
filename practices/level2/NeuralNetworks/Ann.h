#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
struct Node
{
	Node(int input_num)
	{
		init_w(input_num);
	};
	void init_w(int input_num)
	{
		for (int i = 0; i < input_num + 1; i++)
		{
			w.push_back(double((rand() % 100)) / 50 - 1);
		}
	}
	vector<double> w;
	double output;
	double operator*(vector<double>& input)
	{
		double results = 0;
#pragma omp parallel for reduction(+:results)
		for (int i = 0; i < w.size() - 1; i++)
		{
			results += input[i] * w[i];
		}
		results += (-w.back());//最后一个作为阀值
		return (output = (1.0 / (1.0 + exp(-results))));
	}
};
class Ann
{
public:
	Ann(int input_num, int hidden_num, int output_num, double rate);
	~Ann();
	void init_w();
	void set_input(vector<double> input_data);
	vector<double> get_output();
	void train(vector<double> input_data, vector<double> answer);
	void save();
	void load();
private:
	int input_num;//输入数据数
	int hidden_num;//隐藏节点数
	int output_num;//输出节点数量
	double rate;//学习率
	vector<double> temp_data;
	vector<double> last_input_data;
	vector<Node> hidden_node;
	vector<Node> output_node;
	void input_to_hidden();
	void hidden_to_output();

};

