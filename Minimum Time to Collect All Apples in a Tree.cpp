class Solution {
public:

    int dfs(vector<int> adj[],vector<bool> &hasApple,int curr,int par){
        int tot=0;
        for(auto x:adj[curr]){
            if(x!=par) {
                int child_tot=dfs(adj,hasApple,x,curr);
                if(child_tot>0 || hasApple[x]) tot+=child_tot+2;
            }
        }
        return tot;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,hasApple,0,-1);

    }
};