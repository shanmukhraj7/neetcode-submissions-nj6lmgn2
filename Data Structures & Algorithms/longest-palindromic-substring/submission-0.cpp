class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for(auto c : s){
            t += c;
            t += "#";
        }
        int m = t.size();
        vector<int> p(m, 0);
        int r = 0, c = 0;
        for(int i = 0; i < m; i++){
            int mr = 2 * c - i;
            if(i < r) p[i] = min(p[mr], r - i);
            while(i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if(i + p[i] > r){
                r = i + p[i];
                c = i;
            }
        }
        int maxl = 0, cc = 0;
        for(int i = 0; i < m; i++){
            if(p[i] > maxl){
                maxl = p[i];
                cc = i;
            }
        }
        int ss = (cc - maxl) / 2;
        return s.substr(ss, maxl);
    }
};
