class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median;
        if(n % 2 == 1) median = nums[n/2];
        else median = nums[(n/2)-1];
        int res = 0;
        for(int i = 0; i<n; i++) {
            res += abs(median - nums[i]);
        }
        return res;
    }
};