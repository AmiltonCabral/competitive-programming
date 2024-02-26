#include <iostream>
#include <map>

using namespace std;

map<int, long long> memFact = {{0, 1}, {1, 1}};

long long fact(int num) {
    if (memFact[num] != 0) return memFact[num];
    memFact[num] = fact(num - 1) * num;
    return memFact[num];
}


int main() {

    int n1, n2;

    while (scanf("%d %d", &n1, &n2) != EOF)
    {
        cout << fact(n1) + fact(n2) << endl;
    }
 
    return 0;
}