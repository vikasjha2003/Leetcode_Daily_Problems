class Solution {
public:
    int m , n;
    int solve (vector<vector<int>>& grid, int row, int col1, int col2, int (&dp)[70][70][70]) {
        if(row == m) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int res = 0;
        int cur = grid[row][col1];
        if(col1 != col2) cur += grid[row][col2];

        for(int i = -1; i<=1; i++) {
            for(int j = -1; j<=1; j++) {
                int nc1 = col1 + i;
                int nc2 = col2 + j;
                if (nc1 < 0 || nc1 == n ||nc2 < 0 || nc2 == n) continue;
                res = max(res, solve(grid, row + 1, nc1, nc2, dp));
            }
        }

        return dp[row][col1][col2] = cur + res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int dp[70][70][70];
        memset(dp, -1, sizeof(dp));
        
        return solve(grid,0,0,n-1,dp);
    }
};