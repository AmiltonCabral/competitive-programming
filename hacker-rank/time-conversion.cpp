#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    bool AM = s.substr(8, 2) == "AM";
    int hour = stoi(s.substr(0, 2));
    string min = s.substr(3, 2);
    string sec = s.substr(6, 2);

    string newHour;

    if (AM && hour == 12) {
        newHour = "00";
    } else if (AM || (hour == 12 && !AM)) {
        newHour = s.substr(0, 2);
    } else {
        newHour = to_string((hour + 12) % 24);
    }

    return newHour + ':' + min + ':' + sec;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
