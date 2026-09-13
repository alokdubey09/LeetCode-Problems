class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long newTarget = (long long) target- (long long)nums[i]-(long long)nums[j];
                int l=j+1, r=n-1;

                while(l<r){
                    if(nums[l]+nums[r]<newTarget){
                        l++;
                    } else if(nums[l]+nums[r]>newTarget){
                        r--;
                    } else{
                        ans.push_back({nums[i],nums[j], nums[l],nums[r]});
                        int ind1 = l, ind2= r;
                        while(l<r && nums[l]==nums[ind1]) l++;
                        while(l<r && nums[r]== nums[ind2]) r--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
             while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};