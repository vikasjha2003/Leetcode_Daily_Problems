class Solution {
public:

    // Brute Force

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int fun = 0;

        for(int i = 0; i<n; i++) {
            sum += nums[i];
            fun += nums[i] * i;
        }

        int res = fun;

        for(int i = n-1; i>=0; i--) {
            fun += sum - nums[i] * n;
            res = max(res,fun);
        }

        return res;
    }
};