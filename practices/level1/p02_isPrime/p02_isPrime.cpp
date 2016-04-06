#include <iostream>
#include <cmath>
#include <string>

using namespace std;
bool inputIsRight = true;
short charTmparToNum(char ChTmp);
int64_t change(string StrTmp);
void judgeRepeat();
bool judge(int64_t num);

int main() {
	judgeRepeat();
	return 0;
}

short charToNum(char ChTmp) {            //change char to a num;
	short rt;                         //return rt
	if ((int)ChTmp <= (int)'9' && (int)ChTmp >= (int)'0') {
		rt = (int)(ChTmp)-(int)'0';
	}
	else {
		rt = -1;
	}
	return rt;
}


int64_t change(string StrTmp) {
	int len = StrTmp.length();
	int tmp;
	int64_t changedNum = 0;
	inputIsRight = true;
	char charTmp;
	for (tmp = 0; tmp <= len - 1; tmp++) {
		charTmp = StrTmp[tmp];
		if (charToNum(charTmp) != -1) changedNum = 10 * changedNum + charToNum(charTmp);
		else {                                          //½Ã´í»úÖÆ
			cout << "Please cout a true number!!!" << endl;
			cout << endl;
			inputIsRight = false;
			return -1;
			break;
		}

	}
	return changedNum;
}

bool judge(int64_t num) {
	int tmp;
	bool isPrime = true;
	if (num > 2) {
		for (tmp = 2; tmp <= floor(sqrt(num)); tmp++) {
			if (num%tmp == 0) {
				isPrime = false;
			}
		}

	}
	else {
		if (num != 2) {
			isPrime = false;
		}

	}
	return isPrime;
}
void judgeRepeat() {
	string StrTmp;
	int64_t num;
	bool ans;
	while (1) {
		cout << "Please input an number with your keyboard.(exit to close this program)" << endl;
		cin >> StrTmp;
		if (StrTmp == "exit") return;
		num = change(StrTmp);
		ans = judge(num);

		if (inputIsRight) cout << boolalpha << ans << endl;
		cout << endl;
	}
}