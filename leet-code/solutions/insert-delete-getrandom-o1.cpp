#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
   public:
    unordered_map<int, int> idxs;  // key = val; value = index
    vector<int> storage;

    RandomizedSet() {}

    bool insert(int val) {
        if (idxs.count(val)) return false;

        storage.push_back(val);
        idxs[val] = storage.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (!idxs.count(val)) return false;

        // removes from index
        int index = idxs[val];
        idxs.erase(val);

        // update last value if its not the last element
        if (index != storage.size() - 1) {
            storage[index] = storage.back();
            idxs[storage.back()] = index;
        }
        storage.pop_back();

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % storage.size();
        return storage[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */