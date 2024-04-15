class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>>uMap;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        uMap[key].push_back({timestamp,value});
    }

    string get(string key, int timestamp) {
        if (uMap.find(key) == uMap.end()) {
            return "";
        }
        int low = 0, high = uMap[key].size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if (uMap[key][mid].first < timestamp) {
                low = mid + 1;
            } else if(uMap[key][mid].first > timestamp) {
                high = mid - 1;
            } else {
                return uMap[key][mid].second;
            }
        }
        if (high >= 0) {
            return uMap[key][high].second; 
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */