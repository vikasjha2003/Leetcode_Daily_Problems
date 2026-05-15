class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] diff = new int[nums.length];

        for(int i = 0; i<queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            diff[l]--;
            if(r + 1 < diff.length) diff[r+1]++;
        }
        
        int cumsum = 0;

        for(int i = 0; i<diff.length; i++) {
            cumsum += diff[i];
            if(nums[i] + cumsum > 0) return false;
        }

        return true;
    }
}