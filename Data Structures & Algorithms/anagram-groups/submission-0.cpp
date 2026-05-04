class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mpp;
        for(auto& s : strs){
            vector<int> fq(26, 0);
            for(auto c : s) fq[c - 'a']++;
            string key = "";
            for(auto x : fq){
                key += to_string(x) + "%";
            }
            mpp[key].push_back(s);
        }
        for(auto[k, v] : mpp){
            res.push_back(v);
        }
        return res;
    }
};
