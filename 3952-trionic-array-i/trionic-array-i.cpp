class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1;
        int q = -1;
        for(int i = 1; i<nums.size()-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                p = i;
            }else if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                q = i;
            }
        }
        if(p == -1 || q == -1) return false;
        for(int i = 1; i < nums.size() ; i++ ) {
            if(i <= p) {
                if(nums[i-1] >= nums[i]) return false;
            } else if (i <= q) {
                if(nums[i-1] <= nums[i]) return false;
            } else {
                if(nums[i-1] >= nums[i]) return false;
            }
        }
        return true;
    }
};