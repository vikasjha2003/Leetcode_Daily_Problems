class Solution {
public:
    int n;
    long long solve (vector<int>& nums, int idx, bool flag,vector<vector<long long>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];
        long long no_pick = solve(nums,idx + 1,flag,dp);
        int val = nums[idx];
        if(!flag) val = -val;
        long long pick = solve(nums,idx + 1,!flag,dp) + val;
        return dp[idx][flag] = max(pick,no_pick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<long long>> dp (n,vector<long long> (2,-1));
        return solve(nums,0,true,dp);
    }
    
};