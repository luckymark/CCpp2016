#include <iostream>
#include <stack>

using namespace std;

#define FREE_TOWER(from, to) (from != 0 && to != 0 ? 0 : (from != 1 && to != 1 ? 1 : (from != 2 && to != 2 ? 2 : -1)))

stack<int> tows[3];
int n;

void movePlate(int from, int to, int num);

char beautify(int n);

void drawTows();

int main()
{
    cout << "Enter the number of plates: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        tows[0].push(i);
    }
    cout << "Initial status: "<< endl;
    drawTows();
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
    drawTows();
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

void drawTows() {
    stack<int> tmp;
    cout << "--------------------------------------" << endl;
    cout << "A: ";
    auto sz = tows[0].size();
    for (int i = 0; i < sz; ++i) {
        tmp.push(tows[0].top());
        tows[0].pop();
    }
    for (int i = 0; i < sz; ++i) {
        cout << tmp.top() << ' ';
        tows[0].push(tmp.top());
        tmp.pop();
    }
    cout << endl;
    cout << "B: ";
    sz = tows[1].size();
    for (int i = 0; i < sz; ++i) {
        tmp.push(tows[1].top());
        tows[1].pop();
    }
    for (int i = 0; i < sz; ++i) {
        cout << tmp.top() << ' ';
        tows[1].push(tmp.top());
        tmp.pop();
    }
    cout << endl;
    cout << "C: ";
    sz = tows[2].size();
    for (int i = 0; i < sz; ++i) {
        tmp.push(tows[2].top());
        tows[2].pop();
    }
    for (int i = 0; i < sz; ++i) {
        cout << tmp.top() << ' ';
        tows[2].push(tmp.top());
        tmp.pop();
    }
    cout << endl;
    cout << "--------------------------------------" << endl;
}
