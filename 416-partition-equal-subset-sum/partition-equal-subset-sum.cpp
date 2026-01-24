class Solution {
public:
    bool partition(vector<int>& nums, int target, int idx, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(nums.size() == idx || target < 0) return false;
        if(dp[idx][target] != -1) return dp[idx][target];
        return dp[idx][target] = partition(nums,target,idx+1,dp) || partition(nums,target - nums[idx],idx+1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        else {
            int n = sum / 2;
            vector<vector<int>> dp (nums.size(), vector<int> (n+1,-1));
            return partition(nums,n,0,dp);
        } 
    }
};