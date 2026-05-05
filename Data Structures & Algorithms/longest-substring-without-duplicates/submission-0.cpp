class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int maxl = 0, l = 0;
        for(int r = 0; r < n; r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            maxl = max(maxl, r - l + 1);
            st.insert(s[r]);
        }
        return maxl;
    }
};
