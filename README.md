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

// retorna falso se o char c nao for alfa numerico
isalnum(c) == 0

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

### ordered_set

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef **gnu_pbds::tree<int, **gnu_pbds::null_type, less<int>, **gnu_pbds::rb_tree_tag, **gnu_pbds::tree_order_statistics_node_update> ordered_set;

ordered_set st;

//return the number of items in a set that are strictly smaller than our item.
int index = st.order_of_key(16);
```
