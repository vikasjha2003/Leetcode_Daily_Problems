class Solution {
public:

    // Single pass solution

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n,0);
        int pref_sum = 0;
        int suff_sum = 0;

        for(int i = 0; i<n; i++) {
            pref_sum += nums[i];
            suff_sum += nums[n-i-1];
            res[i] += (nums[i] * i) - pref_sum;
            res[n-i-1] += suff_sum - (nums[n-i-1] * i);
        }

        return res;
    }
};