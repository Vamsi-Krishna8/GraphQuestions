class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph,int src,int target,vector<int> &temp){
        temp.push_back(src);
        if(src==target){
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto child:graph[src]){
            dfs(graph,child,target,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=n-1;
        vector<int> temp;
        dfs(graph,0,target,temp);
        return res;
    }
};