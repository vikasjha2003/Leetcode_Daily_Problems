class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini = nums[1];
        int mini1 = INT_MAX;
        for(int i = 2; i<nums.size(); i++) {
            if(nums[i] < mini) {
                mini1 = mini;
                mini = nums[i];
            }else if(nums[i] < mini1) {
                mini1 = nums[i];
            }
        }
        return nums[0] + mini + mini1;
    }
};