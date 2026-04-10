class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, LLONG_MAX));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(coins[i - 1] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        return dp[n][amount] == LLONG_MAX ? -1 : dp[n][amount];
    }
};
