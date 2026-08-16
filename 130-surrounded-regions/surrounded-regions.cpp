class Solution {
private:
    // DelRow and delCol for neighbors
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    /* Helper Function to check if a 
    cell is within boundaries */
    bool isValid(int &i, int &j, 
                 int &n, int &m) {
        
        // Return false if cell is invalid
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        
        // Return true if cell is valid
        return true;
    }
    
    // Recursive function to perform DFS
    void dfs(int row, int col, 
             vector<vector<bool>> &vis,
             vector<vector<char>> &mat, 
             int &n, int &m) {
            
        // Mark the node as visited
        vis[row][col] = true;
        
        // Check the 4 neighbors
        for(int i=0; i < 4; i++) {
            
            // Determine coordinates of new cell
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            /* If an unvisited, valid 
            cell contains 'O' */
            if(isValid(nRow, nCol, n, m) &&
                mat[nRow][nCol] == 'O' &&
                !vis[nRow][nCol] ) {
                
                // Recursive DFS traversal
                dfs(nRow, nCol, vis, mat, n, m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
       
        // Visited array
        vector<vector<bool>> vis(n, vector<bool>(m, false));
       
        // Traverse the boundaries
       
        // Traversal for boundary rows
        for(int j=0; j < m; j++) {
            
            /*Check for unvisited 'O's
            in boundary rows */
           
            // First row
            if(!vis[0][j] && board[0][j] == 'O') {
                // Start DFS traversal from current node
                dfs(0, j, vis, board, n, m); 
            }
           
            // Last row
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                // Start DFS traversal from current node
                dfs(n-1, j, vis, board, n, m); 
            }
        }
        
        // Traversal for boundary columns
        for(int i=0; i < n; i++) {
            
            /*Check for unvisited 'O's
            in boundary columns */
           
            // First column
            if(!vis[i][0] && board[i][0] == 'O') {
                // Start DFS traversal from current node
                dfs(i, 0, vis, board, n, m); 
            }
           
            // Last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                // Start DFS traversal from current node
                dfs(i, m-1, vis, board, n, m); 
            }
        }
        
        /* Traverse the matrix and convert
        the unvisited 'O's into 'X' */
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                
                // Check for unvisited 'O's
                if(board[i][j] == 'O' && 
                  !vis[i][j]) {
                    
                    board[i][j] = 'X';
                }
            }
        }
    }
};