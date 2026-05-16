class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minv = prices[0];
        int maxv = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < minv) minv = prices[i];
            else maxv = max(maxv, prices[i] - minv);
        }
        return maxv;
    }
};
