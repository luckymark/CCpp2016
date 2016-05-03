#include <iostream>

using namespace std;

void crypt(string &data, string key);

int main(int argc, char *argv[]) {
    cout << "Input a sentence: " << endl;
    string data;
    getline(cin, data);
    string key;
    cout << "Input a key: " << endl;
    getline(cin, key);
    crypt(data, key);
    for (char i : data) {
        printf("%0x", (unsigned char)i);
    }
}

void crypt(string &data, string key) {
    size_t keyLen = key.length();
    size_t offset = 0;
    for (char &i : data) {
        i ^= key[offset++ % keyLen];
    }
}
