class Solution {
public:
    int n;
    long long r(vector<int>& nums, vector<int>& colors, vector<long long>& dp, int idx) {
        if(idx == n) return 0;
        if(idx == n-1) return nums[idx];
        if(dp[idx] != -1) return dp[idx];
        long long steal = 0;
        long long leave = 0;
        if(colors[idx+1] == colors[idx]) {
            steal = nums[idx] + r(nums,colors,dp,idx+2);
            leave = r(nums,colors,dp,idx+1);
        } else {
            steal = nums[idx] + r(nums,colors,dp,idx+1);
        }
        return dp[idx] = max(steal , leave);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        if(n == 1) return nums[0];
        vector<long long> dp (n,-1);
        return r(nums,colors,dp,0); 
    }
};