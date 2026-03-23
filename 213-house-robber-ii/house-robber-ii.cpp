class Solution {
public:
    int solve (vector<int> &nums) {
        vector<int> dp (nums.size() + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<=nums.size(); i++) {
            int steal = dp[i-2] + nums[i-1];
            int leave = dp[i-1];
            dp[i] = max(steal,leave);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> start (nums.begin(), nums.end()-1);
        vector<int> end (nums.begin()+1, nums.end());
        return max(solve(start),solve(end));
    }
};