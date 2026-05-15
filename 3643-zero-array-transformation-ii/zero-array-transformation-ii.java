class Solution {
    private boolean isZero(int[] nums, int[][] queries, int mid) {
        int[] diff = new int[nums.length];

        for(int i = 0; i <= mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if(r + 1 < nums.length) diff[r+1] += val;
        }

        int cumsum = 0;

        for(int i = 0; i<nums.length; i++) {
            cumsum += diff[i];
            if(cumsum + nums[i] > 0) return false;
        }

        return true;
    }
    public boolean check (int[] nums, int [][] queries) {
        for(int i = 0; i<nums.length; i++) {
            if(nums[i] != 0) return false;
        }
        return true;
    }
    public int minZeroArray(int[] nums, int[][] queries) {
        if(check(nums,queries)) return 0;

        int low = 0;
        int high = queries.length - 1;

        if(!isZero(nums,queries,high)) return -1;

        int ans = Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isZero(nums,queries,mid)) {
                ans = Math.min(ans,mid+1);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}