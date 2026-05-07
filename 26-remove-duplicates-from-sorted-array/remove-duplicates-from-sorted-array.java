class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int idx = 1, u = 1;
        while(idx < n) {
            if(nums[idx] != nums[u-1]) {
                int temp = nums[u];
                nums[u] = nums[idx];
                nums[idx] = temp;
                u++;
            }
            idx++;
        }
        return u;
    }
}