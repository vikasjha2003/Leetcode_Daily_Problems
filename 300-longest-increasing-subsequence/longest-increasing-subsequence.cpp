class Solution {
public:
    int n ;
    int solve (vector<int>& nums, int idx, int last, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][last] != -1) return dp[idx][last];
        if(nums[idx] > nums[last]) {
            int pick = 1 + solve(nums,idx+1,idx,dp);
            int no_pick = solve(nums,idx+1,last,dp);
            return dp[idx][last] = max(pick,no_pick);
        }
        return dp[idx][last] = solve(nums,idx+1,last,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp (n , vector<int> (n,-1));
        int res = 0;
        for(int i = 0; i<n; i++) {
            res = max(res , 1 + solve(nums,i+1,i,dp));   
        }
        return res;
    }
};