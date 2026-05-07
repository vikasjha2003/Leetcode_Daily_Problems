class Solution {

    public int[] maxValue(int[] nums) {
        int n = nums.length;

        int[] ans = new int[n];
        ans[0] = nums[0];

        // calculate prefixmax

        for(int i = 1; i<n; i++) {
            ans[i] = Math.max(ans[i-1],nums[i]);
        }

        int mini = nums[n-1];

        for(int i = n-2; i>= 0; i--) {
            if(ans[i] > mini) {
                ans[i] = ans[i+1];
            }
            mini = Math.min(mini,nums[i]);
        }
        
        return ans;
    }
}