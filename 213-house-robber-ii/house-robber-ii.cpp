class Solution {
public:
    int solve1 (vector<int> &nums, int idx, vector<int> &dp) { // robbing house 1
        if(idx >= nums.size()-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int steal = nums[idx] + solve1(nums,idx+2,dp);
        int leave = solve1(nums,idx+1,dp);
        return dp[idx] = max(steal , leave);
    }
    int solve2 (vector<int> &nums, int idx, vector<int> &dp) { // robbing last house 
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int steal = nums[idx] + solve2(nums,idx+2,dp);
        int leave = solve2(nums,idx+1,dp);
        return dp[idx] = max(steal , leave);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1 (nums.size(),-1);
        vector<int> dp2 (nums.size(),-1);
        return max(solve1(nums,0,dp1),solve2(nums,1,dp2));
    }
};