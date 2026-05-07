class Solution {

    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] pmax = new int[n];
        int[] smin = new int[n];
        pmax[0] = nums[0];
        smin[n-1] = nums[n-1];

        for(int i = 1; i<n; i++) {
            pmax[i] = Math.max(pmax[i-1],nums[i]);
            smin[n-i-1] = Math.min(smin[n-i], nums[n-i-1]);
        }

        int ans[] = new int[n];
        ans[n-1] = pmax[n-1];

        for(int i = n-2; i>= 0; i--) {
            if(pmax[i] > smin[i+1]) {
                ans[i] = ans[i+1];
            } else {
                ans[i] = pmax[i];
            }
        }
        return ans;
    }
}