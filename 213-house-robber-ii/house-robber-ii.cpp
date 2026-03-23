class Solution {
public:
    int solve (vector<int> &nums, int start, int end) {
        int prev2 = 0;
        int prev1 = nums[start];
        for(int i = start+1; i<end; i++) {
            int steal = prev2 + nums[i];
            int leave = prev1;
            int temp = max(steal,leave);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(solve(nums,0,nums.size()-1),solve(nums,1,nums.size()));
    }
};