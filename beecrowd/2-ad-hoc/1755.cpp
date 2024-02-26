#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


float change(float money, float *brands, int n)
{
    float larger = 0;
    float mod;
    for (int i=0; i<n; i++) {
        if (brands[i] > money) {
            continue;
        }
        mod = fmod(money, brands[i]);
        if (mod > larger) {
            larger = mod;
        }
    }

    return larger;
}


int main()
{
    int T, d, n;
    cin >> T;
    cout << fixed << setprecision(2);
    for (int i = 0; i < T; i++) {
        cin >> d >> n;
        float brands[n];
        for (int j = 0; j < n; j++) {
            cin >> brands[j];
        }
        cout << change((float) d, brands, n) << endl;
    }

    return 0;
}
