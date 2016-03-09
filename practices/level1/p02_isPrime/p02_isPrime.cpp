#include <iostream>
#include <cmath>
#include <string>

using namespace std;
	bool ex=true;
short bc(char ChTmp) {
	short rt;
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
	int otmp;
	int64_t fin = 0;
	ex = true;
	char ch;
	for (otmp = 0; otmp <= len - 1; otmp++) {
		ch = StrTmp[otmp];
		if (bc(ch) != -1) fin = 10 * fin + bc(ch);
		else {
			cout << "Please cout a true number!!!"<<endl;
			cout << endl;
			ex = false;
			return -1;
			break;
		}

	}
	return fin;
}





int main() {
	string StrTmp;
	int64_t num;
	int otmp;
	bool ok;
	while (1) {
		cout << "Please input an number with your keyboard."<<endl;
		cin >> StrTmp;
		if (StrTmp == "exit") return 0;
		num = change(StrTmp);
		ok = true;

		if (num > 2) {
			for (otmp = 2; otmp <= floor(sqrt(num)); otmp++) {
				if (num%otmp==0) ok = false;
			}


		}
		else {
			if (num!=2) ok = false;
		}
		if (ex) cout << boolalpha << ok << endl;
		cout<<endl;
	}
	return 0;
}