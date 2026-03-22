class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = 0; // second previous house
        int prev1 = nums[0]; // previous house
        for(int i = 1; i<n; i++) {
            int steal = nums[i] + prev2;
            int leave = prev1;
            prev2 = prev1;
            prev1 = max(steal,leave);
        }
        return prev1;
    }
};