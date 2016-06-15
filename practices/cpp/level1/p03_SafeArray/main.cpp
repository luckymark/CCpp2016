#include <iostream>
#include "SafeArray.h"

using namespace std;

int main()
{
    int n1,n2;
    cin>>n1;
    SafeArray s1(n1);
    for(int i=0;i<n1;i++){
        s1.write(i,i);
    }
    cin>>n2;
    cout<<s1.read(n2);
    return 0;
}
