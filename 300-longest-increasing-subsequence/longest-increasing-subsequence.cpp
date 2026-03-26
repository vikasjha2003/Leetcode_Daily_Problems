class Solution {
public:
    int n ;
    int solve (vector<int>& nums, int idx, int last, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        // doing last +1 to handle -1 case for index
        if(dp[idx][last+1] != -1) return dp[idx][last+1];
        int pick = 0;
        if(last == -1 || nums[idx] > nums[last]) 
            pick = 1 + solve(nums,idx+1,idx,dp);
        int no_pick = solve(nums,idx+1,last,dp);
        return dp[idx][last+1] = max(pick,no_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp (n , vector<int> (n+1,-1));
        return solve(nums,0,-1,dp);
    }
};