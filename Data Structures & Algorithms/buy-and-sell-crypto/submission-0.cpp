class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mini = a[0];
        int profit = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < mini){
                mini = a[i];
            }
            profit = max(profit, a[i] - mini);
        }
        return profit;
    }
};
