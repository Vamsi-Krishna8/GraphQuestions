class Solution {
public:
    vector<int> res;
    vector<int> freq;
    void dfs(vector<int> adj[], string &labels, int curr, int par) {
        char curr_label = labels[curr];
        int count_before = freq[curr_label - 'a'];
        freq[curr_label - 'a']++;
        for (auto x : adj[curr]) {
            if (x != par) {
                dfs(adj, labels, x, curr);
            }
        }
        int count_after = freq[curr_label - 'a'];
        res[curr] = count_after - count_before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,string labels) {
        res.resize(n);
        freq.resize(26);
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj, labels, 0, -1);
        return res;
    }
};