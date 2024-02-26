#include <iostream>
 
using namespace std;
 
void shift3right(string& row) {
    string aux;
    for (char ch : row) {
        if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z' ) {
            aux += ch + 3;
        } else {
            aux += ch;
        }
    }
    row = aux;
}


void reverse(string& row) {
    string aux = row;
    row = "";
    for (int i=aux.length() -1; i>-1; i--) {
        row += aux[i];
    }
}


void shift1left(string& row) {
    string aux = row.substr(0, row.length() / 2);
    for (char ch : row.substr(row.length() / 2)) {
        aux += ch - 1;
    }
    row = aux;
}


int main() {
    int N, i;
    string row;
    cin >> N;
    cin.ignore();

    for (i=0; i<N; i++) {
        getline(cin, row);
        shift3right(row);
        reverse(row);
        shift1left(row);
        cout << row << endl;
    }
 
    return 0;
}