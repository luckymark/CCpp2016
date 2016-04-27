#include <iostream>

using namespace std;

void movePlate(int from, int to, int num);

int main()
{
    cout << "Enter the number of plates: ";
    cin >> n;
    cout << "Initial status: "<< endl;
    drawTows();
    movePlate('A', 'C', 'B', n);
    return 0;
}

void movePlate(char from, char to, char mid, int num)
{
    if (num == 0)
    {
        return;
    }
    movePlate(from, mid, to, num - 1);
    cout << "from: " << from << " to: " << to << endl;
    movePlate(mid, to, from, num - 1);
}

