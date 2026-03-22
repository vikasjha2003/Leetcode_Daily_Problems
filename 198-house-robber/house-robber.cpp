class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp (n+1,-1);
        // dp[i] = max stolen money till ith house
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<=n; i++) {
            int steal = nums[i-1] + dp[i-2];
            int leave = dp[i-1];
            dp[i] = max(steal , leave);
        }
        return dp[n];
    }
};