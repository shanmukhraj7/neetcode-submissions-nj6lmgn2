class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int c = 0; c <= n; c++){
            int l = c, r = c;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--, r++;
            }
            l = c, r = c + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--, r++;
            }
        }
        return count;
    }
};
