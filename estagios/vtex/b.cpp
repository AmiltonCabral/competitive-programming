#include <bits/stdc++.h>
using namespace std;

int SimpleMode(int arr[], int arrLength) {
  int most = 1;
  unordered_map<int, int> mp;

  for (int i = 0; i < arrLength; ++i) {
    int num = arr[i];
    mp[num]++;
    most = max(most, mp[num]);
  }

  int ans = -1;
  bool valid = false;
  bool found = false;

  for (int i = 0; i < arrLength; ++i) {
    int num = arr[i];
    if (mp[num] == most) {
      if (!found) {
        ans = num;
        found = true;
      }
    } else {
      valid = true;
    }
  }

  if (!valid) {
    return -1;
  }

  return ans;
}

int main(void) {

  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << SimpleMode(A, arrLength);
  return 0;

}