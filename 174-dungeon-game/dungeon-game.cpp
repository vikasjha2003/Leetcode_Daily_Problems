class Solution {
public:
    int m , n;

    int dung (vector<vector<int>>& dungeon, int row , int col, vector<vector<int>> &dp) {
        if(row == m-1 && col == n-1) {
            if(dungeon[row][col] < 0) return dungeon[row][col] - 1;
            return -1;
        }

        if(dp[row][col] != 0) return dp[row][col];

        
        int down = INT_MIN;
        int right = INT_MIN;
        if(row != m-1) down = dung(dungeon,row + 1,col, dp);
        if(col != n-1) right = dung(dungeon,row,col + 1, dp);

        int minfromhere = max(down,right) + dungeon[row][col];

        if(minfromhere < 0) return dp[row][col] = minfromhere;
        else return dp[row][col] = -1; 
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        vector<vector<int>> dp (m, vector<int> (n,0));

        return -1 * dung(dungeon,0,0,dp);
    }
};