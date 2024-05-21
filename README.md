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

// x % y para ponto flutuante
fmod(float x, int y)

// retorna true se str2 é substring de str1
str1.find(str2) != string::npos

// ordenar vetor de palavras pelo tamanho das palavras
sort(all(words), [](const string& a, const string& b) { return a.size() < b.size(); });

// Returns an iterator pointing to the first element in the range [first,last)
// which compares greater than val.
int index = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
```

```cpp
// Faster cin cout
ios_base::sync_with_stdio(0);
cin.tie(0); // don't use on interactive programs
```
