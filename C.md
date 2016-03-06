#C中的结构

###其实就是数据类型(只是复杂的数据类型)

---
###1.结构的声明

*关键字:struct*

例如:

struct funds
    
{
      
      char bank[100];
      double bankfund;
      char save[100];
      double savefund;
  };

---
###2.结构变量和其指针的定义和初始化

struct funds *pf,f,mf[10];//定义结构变量 结构指针 结构数组

或者在声明时就定义

struct funds
    
{
      
      char bank[100];
      double bankfund;
      char save[100];
      double savefund;
  }f,*pf,mf[10];

###初始化变量

初始化结构类似于初始化数组 a[]={1,2,3,4,5};

例如

struct funds fa={"bank of china",3024.72,"savings"，9237.11}；

部分初始化

struct fb={"bank of china"};//这里只对bank[100]进行初始化

###访问结构成员

*运算符(.)(指针用(->))*

例如

f.savingfund=0.0;

pf->savingfund=0.0;

mf[0].savingfund=0.0;

---

###3.嵌套结构

例如:

struct name

{
    
    char first[100];
    char last[100];
};

struct guy

{
    
    struct name handle;
    char favfood[100];
    ...
};

---

###4.结构和函数

**参数问题**

1.传递结构成员

例如

double sum(double x,double y)

{
    
    return x+y;
}

int main()

{
    
    funds f1;
    sum(f1.bankfunds,f1.savingfunds);
}

2.传递结构

double sum(struct funds f)

{
    
    return funds.x+funds.y;
}

3.传递结构地址

double sum(const struct funds *f)//最好加上const

{
    return f->x+f->y;
}

调用函数时

sum(&f);

**返回值**

1.返回简单数据类型(很简单 和其他函数格式一样)

2.返回结构

struct funds(const struct funds f)

{
    
    .....
    return f;
}

---

##结构还是指向结构的指针

指针的优点:只用传一个地址(就是一个数)  缺点：被调函数可能因为一些不经意的操作会影响原来的数据

结构的优点:操作结构的副本保证数据安全 缺点:传递数据量大得多

程序员为了增加效率用指针操作 但最好用const防止指针乱用

---

##结构中的静态变量(结构的计数器)

结构中的静态变量相当于结构中共有的成员

例如

strust point

{
    
    static int num;
    int x;
    int y;
};

int point::num=0;//初始化静态变量

int main()

{
    
    point p[10];
    
    for(int i=0;i<10;i++)
    
    {
     
        p[i].num++;
        .....           
    }
    
    printf("%d",point::num);//此时num=10
}

---

###貌似好像还有一点很有意思的，不过也不是什么高级的东西 提醒大家一下而已

结构的复制

举个例子

 #include<stdio.h>

 #include<stdlib.h>

 #include<string.h>

struct point 
{
  
    int num;
    char *p;  
    
};


int main()
{
    
    point a,b;
    
    a.num=1;
    
    a.p=(char *)malloc(n*sizeof(char));
    
    scanf("%s",a.p);//例如输入 hello
    
    b=a;//注意此处
    
    delete a.p;
    
    printf("%s",b.p);
}

程序运行结果并不会出现hello

原因何在

b=a;是“浅复制”仅仅将p中的内容即指向动态分配的内存的首地址复制
而是用delete将a.p和b.p所指的地址均删除

想要“深复制”就应该这么写

b.num=a.num;

b.p=(char *)malloc(n*sizeof(char));

memset(b,a);



---


**并不是什么大神
没什么编程经验 
只能照本宣科了**






































