class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        unordered_map<int, int> mpp;
        sort(temp.begin(), temp.end());
        int rank = 1;
        for(int i : temp){
            if(!mpp.count(i)){
                mpp[i]=rank;
                rank++;
            }
        }
        vector<int> ans;
        for(int x : arr){
            ans.push_back(mpp[x]);
        }
            return ans;
        }
};