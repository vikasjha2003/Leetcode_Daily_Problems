class Solution {
public:
    int m , n;
    int drow[4] = {1,-1,0,0};
    int dcol[4] = {0,0,1,-1};
    int path(vector<vector<int>> grid, int count, int row, int col) {
        if(grid[row][col] == 2 && count == 0) return 1;
        if(grid[row][col] == 2) return 0;
        grid[row][col] = -1; // marking as visited
        int sum = 0;
        for(int i = 0; i<4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n || grid[nr][nc] == -1) continue;
            sum += path(grid,count - 1,nr,nc);
        }
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int row , col , count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0) count++;
                else if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
            }
        }
        return path(grid,count+1,row,col); // +1 to account for starting
    }
};