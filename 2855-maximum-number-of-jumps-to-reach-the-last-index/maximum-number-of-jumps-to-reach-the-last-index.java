class Solution {

    public int solve (int[] nums, int target, int idx, int[] dp) {
        if(idx == nums.length -1) return 0;
        if(dp[idx] != -2) return dp[idx];
        int res = -1;

        for(int i = idx + 1; i<nums.length; i++) {
            int val = nums[i] - nums[idx];
            if(-target <= val && val <= target) {
                int v = solve(nums,target,i,dp);
                if(v != -1) res = Math.max(res, 1 + v);
            }
        }

        return dp[idx] = res;        
    }

    public int maximumJumps(int[] nums, int target) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-2);
        return solve(nums,target,0,dp);
    }
}