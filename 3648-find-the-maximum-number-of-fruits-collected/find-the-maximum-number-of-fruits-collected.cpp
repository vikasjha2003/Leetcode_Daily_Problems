class Solution {
public:

    int n;

    int c2 (vector<vector<int>>& fruits, int row, int col, vector<vector<int>> &dp) {
        if(row == col) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int res = 0;

        for(int i = -1; i<= 1; i++) {
            if(col + i >= n || col + i <= row) continue;
            res = max(res,c2(fruits,row + 1,col + i, dp));
        }

        return dp[row][col] = res + fruits[row][col];
    }

    int c3 (vector<vector<int>>& fruits, int row, int col,vector<vector<int>> &dp) {
        if(row == col) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int res = 0;

        for(int i = -1; i<= 1; i++) {
            if(row + i >= n || row + i <= col) continue;
            res = max(res,c3(fruits,row + i,col + 1, dp));
        }

        return dp[row][col] = res + fruits[row][col];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        int res = 0;

        for(int i = 0; i<n; i++) {
            res += fruits[i][i];
        }

        vector<vector<int>> dp (n, vector<int> (n,-1));

        res += c2(fruits,0,n-1,dp);

        res += c3(fruits,n-1,0,dp);

        return res;
    }
};