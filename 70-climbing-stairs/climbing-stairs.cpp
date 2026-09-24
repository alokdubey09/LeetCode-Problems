class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        int zeroStep = 1;
        int firstStep = 1;
        int currentStep = 1;
        for (int i = 2; i <= n; i++) {
            currentStep = zeroStep + firstStep;
            firstStep = zeroStep;
            zeroStep = currentStep;
        }
        return currentStep;
    }
};