#include <bits/stdc++.h>
using namespace std;

class TimeMapV1 {
   public:
    unordered_map<string, vector<pair<int, string>>> db;
    TimeMapV1() {}

    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (db[key].empty()) return "";

        int l = 0;
        int r = db[key].size() - 1;

        function<string()> bs = [&]() {
            if (l > r) {
                if (r >= 0) {
                    return db[key][r].second;
                }
                return string();
            }

            int mid = (l + r) / 2;

            if (db[key][mid].first == timestamp) {
                return db[key][mid].second;
            }
            if (db[key][mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            return bs();
        };

        return bs();
    }
};

class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> db;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        string ans = "";
        int l = 0;
        int r = db[key].size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (db[key][m].first <= timestamp) {
                ans = db[key][m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap obj = TimeMap();
    obj.set("love", "high", 10);
    obj.set("love", "low", 20);

    cout << obj.get("love", 5) << endl;
    cout << obj.get("love", 10) << endl;
    cout << obj.get("love", 15) << endl;
    cout << obj.get("love", 20) << endl;
    cout << obj.get("love", 25) << endl;
}