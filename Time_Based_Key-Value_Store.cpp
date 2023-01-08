#include "unordered_map"
#include "string"
#include "vector"
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> ds;
    string binarySearch(vector<pair<int, string>>& kv, int begin, int end, int target) {
        int median = (begin+end)/2;
        if (begin > end) {
            if (end < 0) {
                return "";
            } else {
                return kv[end].second;
            }
        }

        if (target == kv[median].first) {
            return kv[median].second;
        } else if (target > kv[median].first) {
            return binarySearch(kv, median+1, end, target);
        } else {
            return binarySearch(kv, begin, median-1, target);
        }

    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        if (ds.find(key) != ds.end()) {
            return binarySearch(ds[key], 0, ds[key].size()-1, timestamp);
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */