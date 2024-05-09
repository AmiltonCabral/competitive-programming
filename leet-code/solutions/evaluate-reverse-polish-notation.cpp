#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int aux = stk.top();
                stk.pop();
                if (token == "+") {
                    aux += stk.top();
                } else if (token == "-") {
                    aux = stk.top() - aux;
                } else if (token == "*") {
                    aux *= stk.top();
                } else {
                    aux = stk.top() / aux;
                }
                stk.pop();
                stk.push(aux);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};