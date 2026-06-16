class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mpp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!mpp.count(key)) return "";
        auto& a = mpp[key];
        int start = 0, end = a.size() - 1;
        string res = "";
        while(start <= end){
            int mid = start + ((end - start) >> 1);
            if(a[mid].second <= timestamp){
                res = a[mid].first;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return res;
    }
};
