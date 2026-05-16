class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fq(26, 0);
        for(char x : s) fq[x - 'a']++;
        for(char x : t) fq[x - 'a']--;
        for(auto x : fq){
            if(x < 0 || x > 0) return false;
        }
        return true;
    }
};
