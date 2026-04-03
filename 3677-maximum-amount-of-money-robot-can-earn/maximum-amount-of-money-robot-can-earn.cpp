class Solution {
public:
    int m , n;
    
    int solve(vector<vector<int>>& coins, int cnt, int row, int col, vector<vector<vector<int>>>& dp) {
        if(row == m || col == n) return INT_MIN;
        int val = coins[row][col];
        if(row == m-1 && col == n-1) {
            if(cnt == 0 || val >= 0) return val;
            else return 0;
        }
        if(dp[row][col][cnt] != INT_MIN) return dp[row][col][cnt];
        
        if(val >= 0) {
            int down = solve(coins,cnt,row+1,col,dp);
            int right = solve(coins,cnt,row,col+1,dp);
            return dp[row][col][cnt] = max(down , right) + val; 
        }
        else {
            int skip = INT_MIN, take = INT_MIN;
            if(cnt != 0) {
                int down = solve(coins,cnt-1,row+1,col,dp);
                int right = solve(coins,cnt-1,row,col+1,dp);
                skip = max(down,right);
            }
            int down = solve(coins,cnt,row+1,col,dp);
            int right = solve(coins,cnt,row,col+1,dp);
            take = max(down , right) + val; 
            return dp[row][col][cnt] = max(skip,take);            
        }
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int> (3,INT_MIN)));
        return solve(coins,2,0,0,dp);
    }
};