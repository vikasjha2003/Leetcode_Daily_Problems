class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n =  nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;
        int l = 0, r = n-1;
        while(l < n) {
            if((long long)nums[l]*k >= nums[r]) {
                res = l;
                break;
            }
            l++;
        }
        while(l >= 0) {
            while((long long)nums[l]*k < nums[r]) r--;
            res = min ( res , l + n-r-1);
            l--;
        }
        return res;
    }
};