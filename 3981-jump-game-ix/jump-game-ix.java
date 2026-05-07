class Solution {

    public int[] maxValue(int[] nums) {
        int n = nums.length;

        int[] pmax = new int[n];
        pmax[0] = nums[0];

        for(int i = 1; i<n; i++) {
            pmax[i] = Math.max(pmax[i-1],nums[i]);
        }

        int ans[] = new int[n];
        ans[n-1] = pmax[n-1];
        int mini = nums[n-1];

        for(int i = n-2; i>= 0; i--) {
            if(pmax[i] > mini) {
                ans[i] = ans[i+1];
            } else {
                ans[i] = pmax[i];
            }
            mini = Math.min(mini,nums[i]);
        }
        return ans;
    }
}