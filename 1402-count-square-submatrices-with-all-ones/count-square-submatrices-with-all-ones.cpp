class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int totalSquares = 0;

        for(int row =0; row<n;row++){
            for(int col =0; col<m;col++){
                if(matrix[row][col]==0){
                    dp[row][col]=0;
                } else if(row==0 || col==0){
                    dp[row][col]=1; 
                } else {
                    dp[row][col] = 1+min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]});
                }
                totalSquares += dp[row][col];
            }
        }
           return totalSquares;
    }
};