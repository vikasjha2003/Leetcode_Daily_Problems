class Solution {
public:

    int m , n;

    int solve (vector<vector<int>>& grid, int k, int row , int col, vector<vector<vector<int>>> &dp) {
        if(row == m-1 && col == n-1) {
            if (k > 0) return grid[row][col];
            else if (k == 0 && grid[row][col] == 0) return 0;
            else return -1;
        }
        if(dp[row][col][k] != -2) return dp[row][col][k];

        int down = -1, right = -1;

        if(grid[row][col] == 0) {
            if(row != m-1 && k >= 0) down = solve(grid,k,row+1,col,dp);
            if(col != n-1 && k >= 0) right = solve(grid,k,row,col+1,dp);
        } else {
            if(row != m-1 && k > 0) down = solve(grid,k - 1,row+1,col,dp);
            if(col != n-1 && k > 0) right = solve(grid,k - 1,row,col+1,dp);
        } 

        int maxi = max(down,right);
        if(maxi == -1) return dp[row][col][k] = -1;
        return dp[row][col][k] = maxi + grid[row][col];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int> (k+1,-2)));
        return solve(grid,k,0,0,dp);
    }
};