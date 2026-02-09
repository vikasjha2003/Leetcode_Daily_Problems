class Solution {
public:
    int m , n;
    void DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, bool &flag) {
        if(row < 0 || col < 0 || row == m || col == n || visited[row][col] == true || grid[row][col] == 1) return;
        visited[row][col] = true;
        if(row -1 < 0 || col - 1 < 0 || row + 1 == m || col + 1 == n) flag = true;
        DFS(grid , visited , row + 1, col, flag);
        DFS(grid , visited , row - 1, col, flag);
        DFS(grid , visited , row, col + 1, flag);
        DFS(grid , visited , row, col - 1, flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited (m, vector<bool> (n,false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0 && visited[i][j] == false) {
                    bool flag = false;
                    DFS(grid,visited,i,j,flag);
                    if(!flag) count++;
                }
            }
        }
        return count;
    }
};