class Solution {
public:
    // declared here to avoid passing as parameters
    int n;
    int drow[8] = {2,2,1,1,-1,-1,-2,-2};
    int dcol[8] = {1,-1,2,-2,2,-2,1,-1};

    bool res (vector<vector<int>>& grid, int row , int col, int move) {
        if(move == n*n - 1) return true;
        for(int i = 0; i<8; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != move + 1) continue;
            return res(grid,nr,nc,move+1);
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        n = grid.size();
        return res(grid,0,0,0);
    }
};