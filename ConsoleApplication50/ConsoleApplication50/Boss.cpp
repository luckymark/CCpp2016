#include "stdafx.h"
#include "Boss.h"
#include"Texture.h"
#include"Gun.h"
#include"Plane.h"
Boss::Boss()
{
	A.load(13);//还没有导入boss材质
	this->state = 0;
	this->boosliferemain = 200;//boss状态1,待修改[]
	this->setTexture(A.BOSS);
	this->setPosition(520,0);//待修改[]
	this->gun.setOwner(this, 5);//子弹类型待修改[]
	this->launchtoolpoint.setOwner(this);
}

void Boss::heartBeat()
{//需要材质
	switch (this->state)
	{
	case 0:
	{//不要直接fire
		if (this->whetherConversationEnd)
		{
			static int movestage = -1;
			static int count = 0;
			if (count > 50)
			{
				this->fire();
				this->gun.setOwner(this, 6);
				this->fire();
				this->gun.setOwner(this, 5);
				count = 0;
			}
				switch (movestage)
				{
				case -1:
					if (this->getPosition().y <= 50)
						this->move(0, 1);
					else
						movestage++;
					break;

				case 0:
				{
					if (this->getPosition().x > 300)
						this->move(-4.4, 4);
					else
						movestage++;
					break;
				}
				case 1:
				{
					if (this->getPosition().x < 520)
						this->move(4.4, -4);
					else
						movestage++;
					break;
				}
				case 2:
				{
					if (this->getPosition().x < 740)
						this->move(4.4, 4);
					else
						movestage++;
					break;
				}
				case 3:
				{
					if (this->getPosition().x > 520)
						this->move(-4.4, -4);
					else
						movestage = 0;
					break;
				}
				}
				count++;
		}
		else
			if (clock1.getElapsedTime() >= t5)
				this->whetherConversationEnd = 1;//对话占用10s
		break;
	}
	case 1:
	{	static int count = 0;
		if (whetherConversationEnd)
		{
			whetherConversationEnd = 0;
		}
		this->setPosition(520, 50); //没有这句话就飞出去了
		//建议setoweer来更改子弹类型【】

		float a = rand() % 200;
		float b = rand() % 200;
		if (count >= 5)
		{
			this->move(a, b);
			this->fire();
			count = 0;
		}
		count++;
		break;
	}
	case 2:
	{
		//std::cout << "a";
		if (!whetherConversationEnd)
		{//重新初始化
			clock1.restart();
			whetherConversationEnd = 1;
			this->gun.setOwner(this, 7);
			std::cout << "c";
		}
		if (this->whetherCOnversationEnd2)
		{
				this->move(15, 0);
				if (this->getPosition().x > 1024)
					this->setPosition(0, 250);
			if (clock2.getElapsedTime() >= t1)
			{
				this->fire();
				clock2.restart();
			}
		}
		else
			if (clock2.getElapsedTime() >= t5)
			{
				whetherCOnversationEnd2 = 1;
				clock2.restart();
			}
		break;
	}//待补充死亡的类
	case 3:
	{
		std::cout << "d";
		if (whetherCOnversationEnd2)//之前end2的值为1,所以用来初始化,end1的值也为1
		{
			clock1.restart();
			whetherCOnversationEnd2 = 0;
			this->gun.setOwner(this, 8);
			std::cout << "e";
		}
		if (!whetherConversationEnd)
		{
			static int count = 0;
			if (count >= 100)
			{
				this->fire();
				count = 0;
				
			}
			count++;
		}
		else
			if(clock1.getElapsedTime()>=t5)
			{ 
			whetherConversationEnd = 0;
			clock2.restart();//不一定有用
			}
		break;
	}
}
}

bool Boss::needclear()
{
	return this->state==4;
}

void Boss::hit()//一般不能再函数外重新声明函数是因为少打了大括号
{
	this->boosliferemain--;
	if ((this->boosliferemain) <= 0)
		//this->setTexture(A.ENEMY1);//死亡特效1
		//Sound::ENEMY_DOWN.play();
	{
		this->state++;
		switch (this->state)
		{
		case 1:
			this->boosliferemain = 150;
			break;
		case 2:
			this->boosliferemain = 200;
			break;
		case 3:
			this->boosliferemain = 200;
			break;
		case 4:
			break;
		}
	}
}


