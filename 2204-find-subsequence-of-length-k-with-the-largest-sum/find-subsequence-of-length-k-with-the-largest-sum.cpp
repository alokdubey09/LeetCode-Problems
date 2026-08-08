class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
       int n= nums.size();
       for(int i=0;i<n;i++){
        minheap.push({nums[i],i});
        if(minheap.size()>k) minheap.pop();
       }
       vector<int> ans;
       while(!minheap.empty()){
        ans.push_back(minheap.top().second);
        minheap.pop();
       }
       sort(ans.begin(),ans.end());
       for(int i=0;i<ans.size();i++){
        ans[i]=nums[ans[i]];
       }
       return ans;
    }
};