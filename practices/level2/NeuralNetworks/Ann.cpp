#include "stdafx.h"
#include "Ann.h"

Ann::Ann(int input_num, int hidden_num, int output_num, double rate)
{
	this->hidden_num = hidden_num;
	this->input_num = input_num;
	this->output_num = output_num;
	this->rate = rate;
	init_w();
}


Ann::~Ann()
{
}

void Ann::init_w()
{

#pragma omp parallel sections
	{
#pragma omp section
		{
			//初始化隐藏层
			for (int i = 0; i < hidden_num; i++)
			{
				Node temp(input_num);
				hidden_node.push_back(temp);
			}
		}
#pragma omp section
		{
			{
				//初始化输出层
				for (int i = 0; i < output_num; i++)
				{
					Node temp(hidden_num);
					output_node.push_back(temp);
				}
			}
		}
	}
}

void Ann::set_input(vector<double> input_data)
{
	this->temp_data = input_data;
	this->last_input_data = input_data;
}

vector<double> Ann::get_output()
{
	input_to_hidden();
	hidden_to_output();
	if (temp_data.size() != output_num)
	{
		return vector<double>();
	}
	vector<double> temp = temp_data;
	temp_data.clear();
	return temp;
}

void Ann::train(vector<double> input_data, vector<double> answer)
{
	if (answer.size() != output_num)
	{
		return;
	}
	set_input(input_data);
	auto output = get_output();
	vector<double> output_node_sigema(output_num);//输出层梯度
	vector<double> hidden_node_sigema(hidden_num);//隐藏层梯度
	for (int i = 0; i < output_num; i++)
	{
		output_node_sigema[i] = output[i] * (1 - output[i])*(answer[i] - output[i]);
		output_node[i].w[output_node[i].w.size() - 1] -= rate*output_node_sigema[i];//更新输出层阀值
	}
	for (int i = 0; i < output_num; i++)
	{
		for (int j = 0; j < hidden_num; j++)
		{
			output_node[i].w[j] += rate*output_node_sigema[i] * hidden_node[j].output;//更新输出层权值
		}
	}
	for (int i = 0; i < hidden_num; i++)
	{
		double op = hidden_node[i].output, sigma = 0;
		for (int j = 0; j < output_num; j++)
		{
			sigma += output_node_sigema[j] * output_node[j].w[i];
		}
		hidden_node_sigema[i] = op * (1 - op) * sigma;
		hidden_node[i].w[hidden_node[i].w.size() - 1] -= rate*hidden_node_sigema[i];//更新隐藏层阀值
	}
	for (int i = 0; i < hidden_num; i++)
	{
		for (int j = 0; j < input_num; j++)
		{
			hidden_node[i].w[j] += rate*hidden_node_sigema[i] * input_data[j];//更新隐藏层权值
		}
	}
}

void Ann::save()
{
	ofstream f("info.txt");
	for (int i = 0; i < hidden_num; i++)
	{
		for (int j = 0; j < input_num + 1; j++)
			f << hidden_node[i].w[j] << " ";
	}
	for (int i = 0; i < output_num; i++)
	{
		for (int j = 0; j < hidden_num + 1; j++)
			f << output_node[i].w[j] << " ";
	}
	f.close();
}

void Ann::load()
{
	ifstream f("info.txt");
	for (int i = 0; i < hidden_num; i++)
	{
		for (int j = 0; j < input_num + 1; j++)
			f >> hidden_node[i].w[j];
	}
	for (int i = 0; i < output_num; i++)
	{
		for (int j = 0; j < hidden_num + 1; j++)
			f >> output_node[i].w[j];
	}
	f.close();
}


void Ann::input_to_hidden()
{
	if (temp_data.size() != input_num)
	{
		return;
	}
	vector<double> temp(hidden_num);
#pragma omp parallel for
	for (int i = 0; i < hidden_num; i++)
	{
		double results = hidden_node[i] * temp_data;
		temp[i] = results;
	}
	temp_data.clear();
	temp_data = temp;
}

void Ann::hidden_to_output()
{
	if (temp_data.size() != hidden_num)
	{
		return;
	}
	vector<double> temp(output_num);
#pragma omp parallel for
	for (int i = 0; i < output_num; i++)
	{
		double results = output_node[i] * temp_data;
		temp[i] = results;
	}
	temp_data.clear();
	temp_data = temp;
}
