// NeuralNetworks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Ann.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#define OUTPUT_NUM 10
using namespace std;
struct Train_data
{
	vector<double> input;
	vector<double> output;
};
Train_data read_data(Ann* ann);
void train(Train_data data, Ann* ann);
void test(Ann *ann);
int main()
{
	srand((unsigned int)time(NULL));
	Ann ann(64, 20, 10, 0.35);
	read_data(&ann);
	test(&ann);
	system("pause");
	return 0;
}
void train(Train_data data, Ann* ann)
{
	ann->train(data.input, data.output);
	cout << "ok" << endl;
}
Train_data read_data(Ann* ann)
{
	ifstream data("digitstra.txt");
	while (true)
	{
		vector<double> results;
		double bit;
		for (int i = 0; i < 64; i++)
		{
			string temp;
			data >> bit >> temp;
			results.push_back(bit / 16);
		}
		data >> bit;
		vector<double> output(OUTPUT_NUM);
		for (int i = 0; i < OUTPUT_NUM; i++)
		{
			output[i] = (i == bit);
		}
		if (data.eof())
		{
			break;
		}
		train(Train_data{ results,output }, ann);
	}
	ann->save();
	return Train_data();
}
void test(Ann *ann)
{
	ifstream data("digitstest.txt");
	int n = 0;
	int success = 0;
	while (true)
	{
		vector<double> results;
		double bit;
		for (int i = 0; i < 64; i++)
		{
			string temp;
			data >> bit >> temp;
			results.push_back(bit / 16);
		}
		data >> bit;
		if (data.eof())
		{
			break;
		}
		ann->set_input(results);
		auto out = ann->get_output();
		auto position = max_element(out.begin(), out.end());
		int i = distance(out.begin(), position);
		if (i == bit)
		{
			success++;
		}
		n++;
	}
	cout << 1.0*success / n << endl;
	system("pause");
	return;
}