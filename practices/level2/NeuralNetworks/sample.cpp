/*
 * 将三位二进制数转为一位十进制数
 *
 * 作者：zhangdapeng
 *
 */
#include <iostream>
#include <cmath>
#include <time.h>
#include<stdlib.h>

using namespace std;

const int  layer=2;//BP层的数量
const int  in_unit=3;  //输入单元数
const int  hide_unit=10;//隐藏单元数
const int  out_unit=1; //输出单元数
const int  trainsample=8;//BP训练样本数


class BpNet{
public:
    BpNet();
    virtual ~BpNet();

    void weight_init(double w[],int n);
    void init();
    void train(double sample[trainsample][in_unit],double expect[trainsample][out_unit]);//Bp训练
    double recognize(double *p,double expect[trainsample][out_unit]);//Bp识别

    double e;//误差计算
    double error;//允许的最大误差
    double result[out_unit];// Bp输出

private:

    double hiden_w[in_unit][hide_unit];//隐藏单元权重
    double outnode_w[hide_unit][out_unit];//输出单元权重
    double bias_hiden[hide_unit];//隐藏单元偏倚
    double bias_out[out_unit];//输出单元偏倚

    double rate_hiden; //隐藏层权重学习率
    double rate_out;//输出层权重学习率
    double rate_hiden_bias;//隐藏层偏倚学习率
    double rate_out_bias;//输出层偏倚学习率


};

BpNet::BpNet(){
    error=1.0;
    e=0.0;

    rate_hiden=0.9;
    rate_out=0.9;
    rate_hiden_bias=0.9;
    rate_out_bias=0.9;
}

BpNet::~BpNet(){}

void BpNet::weight_init(double w[],int n){ //权重初始化
  srand((unsigned)time(NULL));
  for(int i=0;i<n;i++)
    w[i]=(2.0*(double)rand()/RAND_MAX)-1;
}

void BpNet::init(){
    weight_init((double*)hiden_w,in_unit*hide_unit);
    weight_init((double*)outnode_w,hide_unit*out_unit);
    weight_init(bias_hiden,hide_unit);
    weight_init(bias_out,out_unit);
}

/*
 *sample:输入的样本，expect:期望的输出。
 */
void BpNet::train(double sample[trainsample][in_unit],double expect[trainsample][out_unit]){
    double err_h[hide_unit];//隐藏单元的误差
    double err_o[out_unit];//输出单元的误差


    double ah[hide_unit];//隐藏单元激活值,activation hiden
    double ao[out_unit];//输出单元激活值 activation out
    double sigma[layer];


    for(int ts=0;ts<trainsample;ts++){//循环一次训练样品
        //构造每个样品的输入和输出
        for(int j=0;j<hide_unit;j++){
            sigma[0]=bias_hiden[j];
            for(int i=0;i<in_unit;i++)
                sigma[0]+=hiden_w[i][j]*sample[ts][i];//隐藏层各单元净输入

            ah[j]=1.0/(1+exp(-sigma[0]));//隐藏层各单元的输出
          }

        for(int k=0;k<out_unit;k++){
            sigma[1]=bias_out[k];
            for(int j=0;j<hide_unit;j++)
                sigma[1]+=outnode_w[j][k]*ah[j]; //输出层各单元净输入
            ao[k]=1.0/(1.0+exp(-sigma[1])); //输出层各单元输出

        }

        for(int k=0;k<out_unit;k++){
            err_o[k]=(expect[ts][k]-ao[k])*ao[k]*(1-ao[k]); //希望输出与实际输出的误差
            for(int j=0;j<hide_unit;j++)
                outnode_w[j][k]+=rate_out*err_o[k]*ah[j];  //下一次输出层的新连接权，case update.
        }

        for(int j=0;j<hide_unit;j++){
            err_h[j]=0.0;
            for(int k=0;k<out_unit;k++)
                err_h[j]=err_h[j]+err_o[k]*outnode_w[j][k];
            err_h[j]=err_h[j]*ah[j]*(1-ah[j]); //隐藏层的误差

            for(int i=0;i<in_unit;i++)
                hiden_w[i][j]+=rate_hiden*err_h[j]*sample[ts][i]; //下一次隐藏层的新连接权
        }

        for(int k=0;k<out_unit;k++){
            e+=fabs(expect[ts][k]-ao[k])*fabs(expect[ts][k]-ao[k]); //计算均方差
        }
        error=e/2.0;

        for(int k=0;k<out_unit;k++)
            bias_out[k]=bias_out[k]+rate_out_bias*err_o[k]; //下一次的输出层的新偏倚
        for(int j=0;j<hide_unit;j++)
            bias_hiden[j]=bias_hiden[j]+rate_hiden_bias*err_h[j]; //下一次的隐藏层的新偏倚
    }
}

double BpNet::recognize(double *in,double expect[trainsample][out_unit]){
    double x[in_unit]; //输入向量
    double ah[hide_unit];//隐藏单元激活值
    double ao[out_unit];//输出单元激活值
    double sigma;


    for(int i=0;i<in_unit;i++)
        x[i]=in[i];

    for(int j=0;j<hide_unit;j++){
        sigma=bias_hiden[j];
        for(int i=0;i<in_unit;i++)
            sigma+=hiden_w[i][j]*x[i]; //隐藏层各单元净输入
        ah[j]=1.0/(1.0+exp(-sigma)); //隐藏层各单元输出
    }

    for(int k=0;k<out_unit;k++){
        sigma=bias_out[k];
        for(int j=0;j<hide_unit;j++)
            sigma+=outnode_w[j][k]*ah[j];//输出层各单元净输入
        ao[k]=1.0/(1.0+exp(-sigma));//输出层各单元输出
    }

    for(int k=0;k<out_unit;k++){
        result[k]=ao[k];
    }


    double min=1;
    double index=-1;
    double tmp;
    for(int i=0;i<trainsample;i++){
        for(int j=0;j<out_unit;j++){
            //找误差最小的那个样本
            tmp=(double)(fabs(expect[i][j]-ao[j]));
            if(tmp<min){
                min=tmp;
                index=i;
            }
        }
    }

    return index;
}



int main(){

    //输入样本
    double X[trainsample][in_unit]= {
        {0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}
        };
    //期望输出样本
    double Y[trainsample][out_unit]={
        {0},{0.1429},{0.2857},{0.4286},{0.5714},{0.7143},{0.8571},{1.0000}
        };


    BpNet bp;
    bp.init();
    int times=0;
    while(bp.error>0.0001){
        bp.e=0.0;
        times++;
        bp.train(X,Y);
        if(times % 100 == 0)
            cout<<"Times="<<times<<", Error="<<bp.error<<endl;
    }
    cout<<"trainning complete."<<endl;
    /*
    double in[in_unit]={1,0,1};
    double o=bp.recognize(in,Y);
    for(int i=0;i<in_unit;++i)
       cout<<in[i];
    cout<<" is "<<o<<endl;

    double in2[in_unit]={1,1,1};
    o=bp.recognize(in2,Y);
    for(int i=0;i<in_unit;++i)
       cout<<in2[i];
    cout<<" is "<<o<<endl;
    */
    double in[in_unit];
    while(1){
        cin >> in[0] >> in[1] >> in[2];
        double o = bp.recognize(in,Y);
        for(int i=0;i<in_unit;++i)
           cout<<in[i];
        cout<<" is "<<o<<endl;
    }
    return 0;
}