#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt");
    string str;
    string line;
    while (getline(file, line)) {
        str += line;
    }

    int sum = 0;

    for (int i = 0; i < str.size() - 4; ++i) {
        if (str.substr(i, 4) != "mul(") continue;
        int j = i + 4;
        string strnum = "";

        while (j < str.size() && isdigit(str[j])) {
            strnum += str[j];
            ++j;
        }

        if (str[j] != ',') continue;
        ++j;
        int num = stoi(strnum);
        strnum = "";

        while (j < str.size() && isdigit(str[j])) {
            strnum += str[j];
            ++j;
        }

        if (str[j] != ')') continue;
        num *= stoi(strnum);
        sum += num;
        i = j;
    }

    cout << sum << endl;
}