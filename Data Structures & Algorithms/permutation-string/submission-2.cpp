class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        vector<int> fq1(26, 0);
        vector<int> fq2(26, 0);
        for(int i = 0; i < n; i++){
            fq1[s1[i] - 'a']++;
            fq2[s2[i] - 'a']++;
        }
        if(fq1 == fq2) return true;
        for(int i = n; i < m; i++){
            fq2[s2[i] - 'a']++;
            fq2[s2[i - n] - 'a']--;
            if(fq1 == fq2) return true;
        }
        return false;
    }
};
