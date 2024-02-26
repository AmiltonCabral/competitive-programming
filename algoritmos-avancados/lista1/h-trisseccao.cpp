#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }

    long long sum1=0, sum3=0, max_sum=0;

    for (int i=0, j=n-1; i<=j;) {
        if (sum1 > sum3) {
            sum3 += d[j--];
        } else {
            sum1 += d[i++];
        }

        if (sum1 == sum3) {
            max_sum = sum1;
        }
    }

    cout << max_sum << endl;

    return 0;
}
