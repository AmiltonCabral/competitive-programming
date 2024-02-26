#include <iostream>
#include <stdlib.h>
 
using namespace std;


void real(int notes) {
    cout << "NOTAS:" << endl;

    cout << notes / 100 << " nota(s) de R$ 100.00" << endl;
    notes %= 100;
    cout << notes / 50 << " nota(s) de R$ 50.00" << endl;
    notes %= 50;
    cout << notes / 20 << " nota(s) de R$ 20.00" << endl;
    notes %= 20;
    cout << notes / 10 << " nota(s) de R$ 10.00" << endl;
    notes %= 10;
    cout << notes / 5  << " nota(s) de R$ 5.00"  << endl;
    notes %= 5;
    cout << notes / 2  << " nota(s) de R$ 2.00"  << endl;
    notes %= 2;

    cout << "MOEDAS:" << endl;

    cout << notes << " moeda(s) de R$ 1.00" << endl;
}


void centavos(int coins) {
    cout << coins / 50 << " moeda(s) de R$ 0.50" << endl;
    coins %= 50;
    cout << coins / 25 << " moeda(s) de R$ 0.25" << endl;
    coins %= 25;
    cout << coins / 10 << " moeda(s) de R$ 0.10" << endl;
    coins %= 10;
    cout << coins / 5 << " moeda(s) de R$ 0.05" << endl;
    coins %= 5;
    cout << coins / 1 << " moeda(s) de R$ 0.01" << endl;
}


int main() {
 
    double cash;

    while (cin >> cash)
    {
        real((int) cash);
        centavos((int) (cash * 100) % 100);
    }
 
    return 0;
}


// not used - its only first version backup
int mainOld() {
 
    string cash;
    int dot;

    while (cin >> cash)
    {
        cin.ignore();
        dot = cash.find(".");
        real(stoi(cash.substr(0, dot)));
        centavos(stoi(cash.substr(dot + 1)));
    }
 
    return 0;
}