class Solution {
private: 
    int dp[102][102];
    int func(int left, int right, vector<int>&cuts){
        if(left+1>=right) return 0;

        if(dp[left][right]!=-1) return dp[left][right];
        int cost = INT_MAX;
        
        for (int i = left + 1; i < right; i++) {
            int curr_cost = (cuts[right] - cuts[left]) 
                          + func(left, i, cuts) 
                          + func(i, right, cuts);
            cost = min(cost, curr_cost);
        }
        return dp[left][right] = cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return func( 0, cuts.size()-1, cuts);
    }
};