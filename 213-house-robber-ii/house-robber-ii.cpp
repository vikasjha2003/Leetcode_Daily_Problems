class Solution {
public:
    int solve (vector<int> &nums) {
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i = 2; i<=nums.size(); i++) {
            int steal = prev2 + nums[i-1];
            int leave = prev1;
            int temp = max(steal,leave);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> start (nums.begin(), nums.end()-1);
        vector<int> end (nums.begin()+1, nums.end());
        return max(solve(start),solve(end));
    }
};