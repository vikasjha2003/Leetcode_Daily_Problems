class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int cur = 0;
        int res = 0;
        for(int i = 0; i<n-1; i++) {
            cur += nums[i];
            if(nums[i] > (sum - cur) / (n - i - 1)) res++;
        }
        return res;
    }
};