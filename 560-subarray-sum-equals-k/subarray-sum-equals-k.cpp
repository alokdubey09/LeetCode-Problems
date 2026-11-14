class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> Count;
         Count[0] = 1;

         int currentSum = 0;
        int ans = 0;

        for (int num : nums){
            currentSum += num;
            int target = currentSum - k;
            if (Count.find(target) != Count.end()) {
                ans += Count[target];
            }
            Count[currentSum]++;
        }
        return ans;
    }
};