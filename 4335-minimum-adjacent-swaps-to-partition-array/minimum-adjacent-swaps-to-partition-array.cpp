class Solution {
public:
    static constexpr int MOD = 1000000007;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long swaps =0;
        long long midCount =0;
        long long greaterCount =0;
        for(int num : nums){
            if(num<a){
                swaps = (swaps+midCount+greaterCount)%MOD;
            } else if(num<=b){
                swaps = (swaps+greaterCount)%MOD;
                midCount++;
            } else{
                greaterCount++;
            }
        }
        return swaps;
    }
};