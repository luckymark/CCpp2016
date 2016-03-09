#include <iostream>
#include <vector>

using namespace std;

int length;
int swap(int &a, int &b) {
	int prtmp;

	prtmp = a;
	a = b;
	b = prtmp;
	return 1;
}

int read(vector<int> &array) {
	int inttmp = 0;
	char ch;
	ch = ' ';
	while (1) {
		cin >> ch;
		if (ch = '@') return 4;
		inttmp = (int)ch - (int)'0';
		array.push_back(inttmp);
	}
	return 2;
}

int sort(vector<int> *tmp, bool turn) { //turn=1,2345678 turn=0,9876543
	int otmp, itmp;

	if (turn) {
		length=tmp.size();
		for (otmp = 1; otmp <= length-1; otmp++) {
			for (itmp = 0; itmp <= length - 2; itmp++) {
				if (tmp[itmp] >= tmp[itmp + 1]) {
					swap(tmp[itmp], tmp[itmp + 1]);
				}
			}
		}
	}
	else {
		length = tmp.size();
		for (otmp = 1; otmp <= length-1; otmp++) {
			for (itmp = 0; itmp <= length - 2; itmp++) {
				if (tmp[itmp] <= tmp[itmp + 1]) {
					swap(tmp[itmp], tmp[itmp + 1]);
				}
			}
		}
	}
	return 3;

}



int main() {

	vector<int>  array;
	read(array);
	sort(array, true);
		
	int tmp;
	int atmp = 0;
	for (tmp = 0; tmp <= length-1; tmp++) {
		atmp=array.at(tmp);
		cout << atmp;
	}
	system("pause");
	
	return 0;

}