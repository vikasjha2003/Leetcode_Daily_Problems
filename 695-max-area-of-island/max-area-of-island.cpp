class Solution {
public:
    int m , n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited (m , vector<bool> (n,false));
        int maxi = 0;
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0}; 
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    int sum = 0;
                    while(!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        sum += grid[it.first][it.second];
                        for(int k = 0; k<4; k++) {
                            int row = it.first + drow[k];
                            int col = it.second + dcol[k];
                            if(row < 0 || col < 0 || row == m || col == n || visited[row][col] == true || grid[row][col] == 0) continue;
                            q.push({row,col});
                            visited[row][col] = true;
                        }
                    }
                    maxi = max(sum,maxi);
                }
            }
        }
        return maxi;
    }
};