class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid (n, vector<int> (m,0));
        vector<vector<int>> visited (n, vector<int> (m,0));
        sort(sources.begin(), sources.end(), [] (auto &v1, auto &v2) {
            return v1[2] > v2[2];
        });

        queue<vector<int>> q;
        for(int i = 0; i<sources.size(); i++) {
            visited[sources[i][0]][sources[i][1]] = 1;
            q.push(sources[i]);
        }

        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto it = q.front();
                q.pop();
                
                grid[it[0]][it[1]] = max(grid[it[0]][it[1]],it[2]);

                for(int i = 0; i<4; i++) {
                    int row = it[0] + drow[i];
                    int col = it[1] + dcol[i];
                    if(row < 0 || row == n || col < 0 || col == m || visited[row][col]) continue;
                    visited[row][col] = 1;
                    q.push({row,col,it[2]});
                }
            }
        }
        
        return grid;
    }
};