class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxf = 0, l = 0, maxl = 0;
        vector<int> fq(26, 0);
        for(int r = 0; r < n; r++){
            fq[s[r] - 'A']++;
            maxf = max(maxf, fq[s[r] - 'A']);
            while((r - l + 1) - maxf > k){
                fq[s[l] - 'A']--;
                l++;
            }
            maxl = max(maxl, (r - l + 1));
        }
        return maxl;
    }
};
