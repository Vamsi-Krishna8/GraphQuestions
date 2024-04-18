class Solution {
public:
    int ans;

    int dfs(vector<int> adj[],int curr,int par,string &s){
        int largest=0;
        int second_largest=0;

        for(auto x:adj[curr]){
            if(x==par) continue;
            int child_length=dfs(adj,x,curr,s);
            if(s[x]==s[curr]) continue;
            if(child_length>second_largest) second_largest=child_length;
            if(second_largest>largest) swap(largest,second_largest);
        }
        int only_one=largest+1;
        int only_root=1;
        int both_l_sl=largest+second_largest+1;
        ans=max({ans,only_one,only_root,both_l_sl});
        return max(only_one,only_root);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        ans=0;
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,0,-1,s);
        return ans;
    }
};