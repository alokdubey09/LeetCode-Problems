class Solution {
private: 
    void dfs(int node, vector<vector<int>> &adjLs, vector<int>& vis, int &nodes, int &sum){
        vis[node]=1;
        nodes++;
        sum +=adjLs[node].size();
        for(int neigh : adjLs[node]){
            if(!vis[neigh])
                dfs(neigh, adjLs, vis, nodes, sum);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLs(n);
        for(auto &edge : edges){
            adjLs[edge[0]].push_back(edge[1]);
            adjLs[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        int ans =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes =0;
                int sum=0;
                dfs(i, adjLs, vis, nodes, sum);
                int cnt = sum/2;
                if(cnt==nodes*(nodes-1)/2) ans++;
            }
        }
        return ans;
    }
};