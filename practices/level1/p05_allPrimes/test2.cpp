#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int i,j,prime[1005],num,vis[1005];
clock_t pre,fin;
int main(){
	pre=clock();
	for(i=2;i<=1000;++i){
		if(vis[i])continue;
		prime[num++]=i;
		for(j=2;j*i<=1000;++j){
			vis[j*i]=1;
		}
	}
	for(i=0;i<num;++i){
		printf("%d%c",prime[i],(i==num-1)?'\n':' ');
	} 
	fin=clock();
	printf("%dms",(int)fin-pre);
	return 0;
}
//+t完全是手抖...我的锅... 0.0
//just try again after watching sydney FC 2 - 1 Guangzhou evergrande
