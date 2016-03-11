#include <iostream>
#include <cstdio>
using namespace std;

char str[]={'A','B','C'};
void hanio(int n, int s, int t){
	if(n == 1){
		printf("%c -> %c\n", str[s], str[t]);
		return ;
	}
	bool vis[] = {true, true, true};
	vis[s] = vis[t] = false;
	int other;
	for(other = 0; other < 3; ++other){
		if(vis[other])
			break;
	}
	hanio(n-1, s, other);
	printf("%c -> %c\n", str[s], str[t]);
	hanio(n-1, other, t);
}
int main(){
	int n;
	while(cin >> n){
		hanio(n, 0, 2);
	}
	return 0;
}
