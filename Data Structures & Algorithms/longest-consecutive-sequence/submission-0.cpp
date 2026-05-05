class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxv = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto num : st){
            if(st.find(num - 1) == st.end()){
                int len = 1;
                while(st.count(num + len)){
                    len++;
                }
                maxv = max(maxv, len);
            }
        }
        return maxv;
    }
};
