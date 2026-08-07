class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans =0;
        for(auto & r : grid) sort(r.begin(), r.end());

        for(int i=0;i<grid[0].size();++i){
            int maxEle =0;
            for(int j=0;j<grid.size();++j){
                maxEle = max(maxEle, grid[j][i]);
            }
            ans +=maxEle;
        }
        return ans;
    }
};