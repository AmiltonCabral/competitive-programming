#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    int num;
    char comma;
    vector<int> out;

    ss >> num;
    out.push_back(num);

    while (!ss.eof()) {
        ss >> comma;
        ss >> num;
        out.push_back(num);
    }
    
    return out;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}