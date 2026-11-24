class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int ans = 0;
        int maxLen =0;
        int[] dp = new int[n];
        int[] cnt = new int[n];

        Arrays.fill(dp, 1);
        Arrays.fill(cnt, 1);

        for(int i=0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i]= dp[j]+1;
                        cnt[i]= cnt[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxLen = Math.max(maxLen, dp[i]);
        }
        for(int k = 0;k<n;k++){
            if(dp[k]==maxLen) ans+=cnt[k];
        }
        return ans;
    }
}