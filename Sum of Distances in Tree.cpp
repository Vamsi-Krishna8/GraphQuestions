class Solution {
public:
    vector<vector<int> > adj;
    vector<int> subCount;
    vector<int> res;
    int root_res=0;

    int dfs(int curr,int par,int depth){  //0,-1,0
        int count=1;
        root_res+=depth;
        for(auto x:adj[curr]){
            if(x==par) continue;
            count+=dfs(x,curr,depth+1);
        }
        subCount[curr]=count;
        return count;
    }
    void dfs1(int curr,int par,int n){
        for(auto child:adj[curr]){
            if(child==par) continue;
            res[child]=res[curr]-subCount[child]+(n-subCount[child]);
            dfs1(child,curr,n);
        }
    } 
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        subCount.resize(n);
        res.resize(n);
        for(int i=0;i<n-1;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        root_res=0;
        dfs(0,-1,0);
        res[0]=root_res;
        dfs1(0,-1,n);
        return res;
    }
};