class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // marked visited;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> temp = q.front();
                int i = temp.first;
                int j = temp.second;
                q.pop();
                if (!(i == entrance[0] && j == entrance[1]) &&
                    (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    return steps;
                }
                for (auto x : dir) {
                    int new_i = i + x[0];
                    int new_j = j + x[1];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                        maze[new_i][new_j] != '+') {
                        q.push({new_i, new_j});
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};