class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        int res = Integer.MAX_VALUE;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            res = Math.min(nums[mid],res);
            if(nums[low] == nums[high]) {
                high--;
                continue;
            }
            if(nums[high] < nums[mid]) low = mid+1;
            else high = mid - 1;
        }

        return res;
    }
}