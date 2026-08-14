class Solution {
private: 
    void bfs(int node, vector<vector<int>> &adj, vector<int>& vis) {
        vis[node] = 1;
        queue <int> q;
        q.push(node); 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int adjNode=0; adjNode<adj.size();adjNode++) {
                if(adj[curr][adjNode] == 1 && !vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int V = isConnected.size();
         vector<int> vis(V, 0);
        int cnt = 0;
        for(int i=0; i < V; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i, isConnected, vis); 
            }
        }
        return cnt; 
    }
};