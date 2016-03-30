#include <iostream>
#include <vector>

using namespace std;

int length;
vector<int>  tarray;

void swap(int &a, int &b);
void inp();
void outp();
void sortp();

int main() {

	inp();
	length = tarray.size();
	sortp();
	outp();
	system("pause");

	return 0;

}

void swap(int &a, int &b) {
	int prtmp;

	prtmp = a;
	a = b;
	b = prtmp;
}

void inp() {
	int inttmp = 0, tmp;
	cout << "Please input the length of the line of numbers:";
	cin >> inttmp;
	cout << "The numbers is (will be reordered Min to Max): ";

	int ch;
	for (tmp = 0; tmp <= inttmp - 1; tmp++) {
		cin >> ch;
		tarray.push_back(ch);
	}
}

void outp() {
	int tmp;
	int atmp = 0;
	for (tmp = 0; tmp <= length - 1; tmp++) {
		atmp = tarray.at(tmp);
		cout << atmp << ' ';
	}
}

void sortp() {


	int otmp, itmp;

	for (otmp = 1; otmp <= length - 1; otmp++) {
		for (itmp = 0; itmp <= length - 2; itmp++) {
			if (tarray[itmp] >= tarray[itmp + 1]) {
				swap(tarray[itmp], tarray[itmp + 1]);
			}
		}
	}


}