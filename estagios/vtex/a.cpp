#include <bits/stdc++.h>
using namespace std;

string WordSplit(string strArr[], int arrLength) {
  unordered_set<string> st;

  string sbstring = "";
  for (char ch : strArr[1]) {
    if (ch != ',') {
      sbstring.push_back(ch);
    } else {
      st.insert(sbstring);
      sbstring = "";
    }
  }
  st.insert(sbstring);

  for (int i = 1; i < strArr[0].length(); ++i) {
    string subl = strArr[0].substr(0, i);
    int numCharSubr = strArr[0].length() - i;
    string subr = strArr[0].substr(i, numCharSubr);

    if (st.count(subl) && st.count(subr)) {
      string ans = subl + ',' + subr;
      reverse(ans.begin(), ans.end());
      ans += ":6f1wajdik";
      return ans;
    }
  }

  return "elbissop ton:6f1wajdik";
}

int main(void) {
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << WordSplit(A, arrLength);
  return 0;
}