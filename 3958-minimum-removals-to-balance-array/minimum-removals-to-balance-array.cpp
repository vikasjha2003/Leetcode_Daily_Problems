class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int l = 0 , r = 0 , res = 0;
        while(r < n) {
            while((long long) nums[l]*k < nums[r]) l++;
            res = max (res , r - l + 1);
            r++;
        }
        return n - res;
    }
};