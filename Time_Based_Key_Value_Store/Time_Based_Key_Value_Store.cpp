// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    map<pair<string, int>, string> mp;
    map<string, set<int>> stamps;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key, timestamp}] = value;
        stamps[key].insert(stamps[key].end(), timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!empty(stamps[key])) {
            auto it = stamps[key].upper_bound(timestamp);
            if (it != stamps[key].begin()) {
                --it;
                    return mp[{key, *it}];
            } else {
                return "";
            }
        }

        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
