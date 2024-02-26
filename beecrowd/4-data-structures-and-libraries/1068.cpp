#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void verifyBalanceCount(string str) {
    stringstream ss(str);
    char ch;
    int count = 0;

    while (true)
    {
        ss >> ch;
        if (ss.eof()) break;

        if (ch == '(') {
            count++;
        }
        if (ch == ')') {
            if (count == 0) {
                cout << "incorrect" << endl;
                return;
            }
            count--;
        }
    }
    
    if (count == 0) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
}


void verifyBalance(string str) {
    stack<char> stk;
    stringstream ss(str);
    char ch;

    while (true)
    {
        ss >> ch;
        if (ss.eof()) break;

        if (ch == '(') {
            stk.push('(');
        }
        if (ch == ')') {
            if (stk.empty()) {
                cout << "incorrect" << endl;
                return;
            }
            stk.pop();
        }
    }
    
    if (stk.empty()) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
}


int main() {
    string line;
    
    while (getline(cin, line)) {
        verifyBalance(line);
    }
 
    return 0;
}