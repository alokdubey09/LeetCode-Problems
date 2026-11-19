class Solution {
private: 
    int MOD = 1e9+7;
    int func(vector<int>&coins, int ind, int T, vector<vector<long long>>&dp){
        if(ind==0){
            return (T%coins[0]==0);
        }
        if(dp[ind][T]!=-1)
            return dp[ind][T];
        int notPick = func(coins, ind-1, T, dp);
        int pick = 0;
        if(coins[ind]<=T){
            pick = func(coins, ind, T-coins[ind], dp);
        }
        return dp[ind][T] = (notPick + pick);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));
        return func(coins, n-1, amount, dp);
    }
};