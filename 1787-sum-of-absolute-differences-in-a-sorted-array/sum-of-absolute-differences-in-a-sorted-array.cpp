class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref (n,0);
        vector<int> suff (n,0);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1; i<n; i++) {
            pref[i] = pref[i-1] + nums[i];
            suff[n-i-1] = suff[n-i] + nums[n-i-1];
        }

        vector<int> res(n);

        for(int i = 0; i<n; i++) {
            int left = (nums[i] * i) - pref[i];
            int right = suff[i] - (nums[i] * (n-i-1));
            res[i] = left + right;
        }

        return res;
    }
};