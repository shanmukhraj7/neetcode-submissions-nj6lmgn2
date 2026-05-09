class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int length = strs.size();
        unordered_map<string, vector<string>> stringStorage;
        for(string& str : strs){
            vector<int> frequencyArray(26, 0);
            for(char ch : str){
                frequencyArray[ch - 'a']++;
            }
            string key = "";
            for(int i = 0; i < frequencyArray.size(); i++){
                key += to_string(frequencyArray[i]) + "$";
            }
            stringStorage[key].push_back(str);
        }
        for(auto& it : stringStorage){
            string key = it.first;
            vector<string> value = it.second;
            result.push_back(value);
        }
        return result;
    }
};
