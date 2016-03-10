#include <iostream>
#include <stack>

using namespace std;

#define FREE_TOWER(from, to) (from != 0 && to != 0 ? 0 : (from != 1 && to != 1 ? 1 : (from != 2 && to != 2 ? 2 : -1)))

stack<int> tows[3];
int n;

void movePlate(int from, int to, int num);

char beautify(int n);

int main()
{
    cout << "Enter the number of plates: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        tows[0].push(i);
    }
    movePlate(0, 2, n);
    return 0;
}

void movePlate(int from, int to, int num) {
    if (num == 0) {
        return;
    }
    movePlate(from, FREE_TOWER(from, to), num - 1);
    tows[to].push(tows[from].top());
    tows[from].pop();
    cout << "from: " << beautify(from) << " to: " << beautify(to) << endl;
    movePlate(FREE_TOWER(from, to), to, num - 1);
}

char beautify(int n) {
    switch (n) {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    }
    return '/';
}
