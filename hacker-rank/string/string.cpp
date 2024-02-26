#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    cout << str1.size() << " " << str2.size() << endl;
    cout << str1 + str2 << endl;

    char aux = str1[0];
    str1[0] = str2[0];
    str2[0] = aux;

    cout << str1 << " " << str2 << endl;
  
    return 0;
}