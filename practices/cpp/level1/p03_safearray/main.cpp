#include <iostream>
#include "SafeArray.h"
#define MAX 100
using namespace std;
int main()
{
    SafeArray m(MAX);
    int n,item;
    cin >> n,item;
    if (m.check(n)){
        m.clone(n,item);
    }
    else{
        cout << "error!" << endl;
    }
    return 0;
}
