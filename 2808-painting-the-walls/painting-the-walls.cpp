class Solution {
private: 
    int func(vector<int>&cost, vector<int>&time, int index, int walls, vector<vector<int>>&dp){
        if(walls<=0) return 0;
        if(index<0) return 1e9;
        if(dp[index][walls]!=-1) return dp[index][walls];

        int notPick = 0+func(cost, time, index-1, walls, dp);
        int pick = cost[index] + func(cost, time, index-1, walls-time[index]-1, dp);

        return dp[index][walls] = min(notPick, pick);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return func(cost, time, n-1, n, dp);
    }
};