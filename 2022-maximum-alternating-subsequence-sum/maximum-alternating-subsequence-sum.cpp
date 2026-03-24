class Solution {
public:
    int n;
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<long long>> dp (n+1,vector<long long> (2,0));
        // 0 = even , 1 = odd
        for(int i = 1; i<=n; i++) {
            int val = nums[i-1];
            for(int j = 0; j<2; j++) {
                if(j == 1) val = -val;
                long long skip = dp[i-1][j];
                long long take = dp[i-1][!j] + val;
                dp[i][j] = max(skip,take);
            }
        }
        return max(dp[n][0],dp[n][1]);
    }
    
};