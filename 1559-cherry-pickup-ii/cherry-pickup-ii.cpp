class Solution {
public:
    int m , n;
    int solve (vector<vector<int>>& grid, int row, int col1, int col2, int (&dp)[70][70][70]) {
        if(row == m || col1 < 0 || col1 == n || col2 < 0 || col2 == n) return 0;
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int res = 0;

        for(int i = -1; i<=1; i++) {
            int a = grid[row][col1];
            grid[row][col1] = 0;
            for(int j = -1; j<=1; j++) {
                int b = grid[row][col2];
                grid[row][col2] = 0;
                int profit = a + b + solve(grid,row+1,col1 + i,col2 + j, dp);
                res = max(res,profit);
                grid[row][col2] = b;
            }
            grid[row][col1] = a;
        }

        return dp[row][col1][col2] = res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int dp[70][70][70];
        memset(dp, -1, sizeof(dp));
        return solve(grid,0,0,n-1,dp);
    }
};