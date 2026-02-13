class Solution {
public:
    int helper (vector<vector<int>>& grid,int m, int n, vector<vector<int>>& dp) {
        if(m<0 || n<0) return INT_MAX;
        if(m == 0 && n == 0) return grid[0][0];
        if(dp[m][n] != -1) return dp[m][n];
        int left = helper(grid ,m ,n-1 ,dp);
        int up = helper(grid ,m-1 ,n ,dp);
        return dp[m][n] = grid[m][n] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size() , vector<int> (grid[0].size(), -1));
        return helper(grid, grid.size()-1, grid[0].size()-1, dp);
    }
};