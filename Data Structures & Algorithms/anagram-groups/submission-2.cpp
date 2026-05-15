class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        for(auto s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s);
        }
        for(auto it : mpp){
            res.push_back(it.second);
        }
        return res;
    }
};
