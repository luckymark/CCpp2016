#include <iostream>
#include "SafeArray.h"
#define MAX 100
using namespace std;
int main()
{
    SafeArray a(MAX);
    int n,item;
    cin >> n,item;
    if (a.check(n)){
        a.clone(n,item);
    }
    else{
        cout << "error!" << endl;
    }
    return 0;
}
