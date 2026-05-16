class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxv = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto x : st){
            if(!st.count(x - 1)){
                int len = 1;
                while(st.count(x + len)) len++;
                maxv = max(maxv, len);
            }
        }
        return maxv;
    }
};
