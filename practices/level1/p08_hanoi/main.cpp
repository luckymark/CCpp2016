#include <iostream>
#include <vector>

using namespace std;

vector<int> tows[3];
int n;

void movePlate(int from, int to, int num);

char beautify(int n);

void drawTows();

int main()
{
    cout << "Enter the number of plates: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        tows[0].push_back(i);
    }
    cout << "Initial status: "<< endl;
    drawTows();
    movePlate(0, 2, 1, n);
    return 0;
}

void movePlate(int from, int to, int mid, int num)
{
    if (num == 0)
    {
        return;
    }
    movePlate(from, mid, to, num - 1);
    tows[to].push_back(tows[from].top());
    tows[from].pop_back();
    cout << "from: " << beautify(from) << " to: " << beautify(to) << endl;
    drawTows();
    movePlate(mid, to, from, num - 1);
}

char beautify(int n)
{
    switch (n)
    {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    }
    return '/';
}

void drawTows()
{
    cout << "--------------------------------------" << endl;
    for (int towI = 0; towI < 3; ++towI)
    {
        cout << beautify(towI) << ": ";
        for (auto plate : tows[towI]) {
            cout << plate;
        }
        cout << endl;
    }
    cout << "--------------------------------------" << endl;
}
