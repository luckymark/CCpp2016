#pragma once
#include<iostream>
using namespace std;
class Button
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
};
class Fan :public Button
{
public:
	Fan(){}
	void on() 
	{
		cout << "打开电扇" << endl; 
	}
	void off() 
	{
		cout << "关闭电扇" << endl; 
	}
};
class Door :public Button
{
public:
	virtual void on() 
	{
		cout << "开门" << endl; 
	}
	virtual void off() 
	{
		cout << "关门" << endl; 
	}
};
class Light :public Button
{
public:
	virtual void on() 
	{ 
		cout << "打开电灯" << endl; 
	}
	virtual void off() 
	{ 
		cout << "关闭电灯" << endl; 
	}
};