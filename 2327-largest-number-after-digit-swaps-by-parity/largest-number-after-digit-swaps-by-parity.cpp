class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd;
        priority_queue<int> even;

        string nums= to_string(num);

        int n = nums.size();

        for(int i=0;i<n;i++){
            int digit = nums[i]-'0';
            if(digit%2) odd.push(digit);
            else even.push(digit);
        }
        int ans = 0;
        for(int j=0;j<n;j++){
            ans = ans*10;
            if((nums[j]-'0')%2){
                ans +=odd.top();
                odd.pop();
            }
            else {
                ans +=even.top();
                even.pop();
            }
        }
        return ans;
    }
};