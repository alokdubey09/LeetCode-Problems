class Solution {
private:
    bool f(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0)
           return true;
        if(ind==0)
           return nums[0]==target;
        if(dp[ind][target]!=-1)
           return dp[ind][target];
        bool notPick = f(ind-1, target, nums, dp);
        bool pick = false;
        if(nums[ind]<=target)
           pick = f(ind-1, target-nums[ind],nums, dp);

        return dp[ind][target] = notPick || pick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum =0;
        for(int i=0;i<n;i++){
            totalSum +=nums[i];
        }
        if(totalSum%2==1)
           return false;
        else{
            int k = totalSum/2;
            vector<vector<int>> dp(n, vector<int>(k+1, -1));
            return f(n-1,k,nums, dp);
        }
    }
};