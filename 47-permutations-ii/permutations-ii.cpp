class Solution {
private: 
    void function(vector<int> nums, int i, int j, vector<vector<int>> &ans){
        if(i==j-1){
            ans.push_back(nums);
            return;
        }
        for(int k = i;k<j;k++){
            if(i!=k && nums[i]== nums[k]) continue;
            swap(nums[i], nums[k]);
            function(nums, i+1, j, ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        function(nums, 0, nums.size(), ans);
        return ans;
    }
};