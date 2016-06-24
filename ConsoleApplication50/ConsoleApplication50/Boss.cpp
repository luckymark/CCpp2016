#include "stdafx.h"
#include "Boss.h"
#include"Texture.h"
#include"Gun.h"
#include"Plane.h"
Boss::Boss()
{
	A.load(13);//��û�е���boss����
	this->state = 0;
	this->boosliferemain = 200;//boss״̬1,���޸�[]
	this->setTexture(A.BOSS);
	this->setPosition(520,0);//���޸�[]
	this->gun.setOwner(this, 5);//�ӵ����ʹ��޸�[]
	this->launchtoolpoint.setOwner(this);
}

void Boss::heartBeat()
{//��Ҫ����
	switch (this->state)
	{
	case 0:
	{//��Ҫֱ��fire
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
				this->whetherConversationEnd = 1;//�Ի�ռ��10s
		break;
	}
	case 1:
	{	static int count = 0;
		if (whetherConversationEnd)
		{
			whetherConversationEnd = 0;
		}
		this->setPosition(520, 50); //û����仰�ͷɳ�ȥ��
		//����setoweer�������ӵ����͡���

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
		{//���³�ʼ��
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
	}//��������������
	case 3:
	{
		std::cout << "d";
		if (whetherCOnversationEnd2)//֮ǰend2��ֵΪ1,����������ʼ��,end1��ֵҲΪ1
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
			clock2.restart();//��һ������
			}
		break;
	}
}
}

bool Boss::needclear()
{
	return this->state==4;
}

void Boss::hit()//һ�㲻���ٺ���������������������Ϊ�ٴ��˴�����
{
	this->boosliferemain--;
	if ((this->boosliferemain) <= 0)
		//this->setTexture(A.ENEMY1);//������Ч1
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


