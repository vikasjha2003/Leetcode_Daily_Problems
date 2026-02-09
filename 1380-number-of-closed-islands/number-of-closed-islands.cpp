class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        int count = 0;
        vector<vector<bool>> visited (m, vector<bool> (n,false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0 && visited[i][j] == false) {
                    bool flag = false;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()) {
                        auto &it = q.front();
                        visited[it.first][it.second] = true;
                        if(it.first -1 < 0 || it.second - 1 < 0 || it.first + 1 == m || it.second + 1 == n) flag = true;
                        for(int k = 0; k < 4; k++) {
                            int row = it.first + drow[k];
                            int col = it.second + dcol[k];
                            if(row < 0 || col < 0 || row == m || col == n || visited[row][col] == true || grid[row][col] == 1) continue;
                            q.push({row,col});
                        }
                        q.pop();
                    }
                    if(!flag) count++;
                }
            }
        }
        return count;
    }
};