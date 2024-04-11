class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());
        unordered_set<string> vis;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        int ans=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr_top=q.front();
                q.pop();
                if(curr_top==end){
                    return ans;
                }
                for(char ch:"ACGT"){
                    for(int i=0;i<8;i++){
                        string temp=curr_top;
                        temp[i]=ch;
                        if(bankset.find(temp)!=bankset.end() && vis.find(temp)==vis.end()){
                            vis.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};