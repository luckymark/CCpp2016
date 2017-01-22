#include <cstdio>
#include <cstring>

#define PRIME_SIZE 100

bool prime_vis[PRIME_SIZE + 10];
int prime[PRIME_SIZE],prime_cnt;

void getPrime();
bool check(int prime[], bool prime_vis[], int prime_cnt);

int main(){
    getPrime();
    bool result = check(prime, prime_vis, prime_cnt);
    if(result){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

void getPrime(){
    memset(prime_vis, 0, sizeof(prime_vis));
    prime_cnt = 0;
    for(int i = 2; i <= PRIME_SIZE; ++i){
        if(!prime_vis[i]){
            prime[prime_cnt++] = i;
            for(int j = i; j <= PRIME_SIZE; j += i){
                prime_vis[j] = true;
            }
        }
    }
}

bool check(int prime[], bool prime_vis[], int prime_cnt){
    for(int num = 4; num <= 100; num += 2){
        bool flag = false;
        for(int i = 0; i < prime_cnt && num > prime[i]; ++i){
            if(prime_vis[num-prime[i]]){
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }
    return true;
}
