# Competitive Programming

## C++ tips

```sh
# compile and execute
g++ -o \_exe ./code.cpp && ./\_exe
gcc -o \_exe ./code.cpp && ./\_exe
```

```cpp
vector<int> arr(100);
int val = 5;

// Returns an iterator pointing to the first element in the range [first,last)
// which compares greater than val.
int index = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
```
