class Solution {
public:

    bool bfs(int node,vector<int> adj[],vector<int> &colour){
        queue<int> q;
        q.push(node);
        colour[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto x:adj[curr]){
                if(colour[x]!=-1){
                    if(colour[x]==colour[curr]) return false;
                }
                else if(colour[x]==-1){
                    colour[x]=1-colour[curr];
                    q.push(x);
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colour(n+1,-1); //-1 is not processed yet , 1 is red colour , 0 is green colour
        for(int i=1;i<=n;i++){
            if(colour[i]==-1){
                if(!(bfs(i,adj,colour))){
                    return false;
                }
            }
        }
        return true;
    }
};