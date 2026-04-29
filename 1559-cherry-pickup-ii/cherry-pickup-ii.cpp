class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[71][71][71];
        memset(dp, 0, sizeof(dp));

        int maxi = 0;

        for(int row = m-1; row>= 0; row--) {
            for (int col1 = min(row,n-1); col1 >= 0; col1--) {
                for(int col2 = max(0,n - row -1); col2 < n; col2++) {
                    int cur = grid[row][col1];
                    if(col1 != col2) cur += grid[row][col2];
                    int res = 0;
                    for(int i = -1; i <= 1; i++) {
                        if(col1 + i < 0 || col1 + i == n) continue;
                        for(int j = -1; j<= 1; j++) {
                            if(col2 + j < 0 || col2 + j == n) continue;
                            res = max(res,dp[row + 1][col1 + i][col2 + j]);
                        }
                    }
                    dp[row][col1][col2] = cur + res;
                    maxi = max(maxi,dp[row][col1][col2]);
                }
            }
        }

        return maxi;
    }
};