class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr (101,0);
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] % 2 == 0) {
                arr[nums[i]]++;
            }
        }
        for(int i = 0; i<n; i++) {
            if(nums[i] % 2 == 0) {
                if(arr[nums[i]] == 1) return nums[i];
            }
        }
        return -1;
    }
};