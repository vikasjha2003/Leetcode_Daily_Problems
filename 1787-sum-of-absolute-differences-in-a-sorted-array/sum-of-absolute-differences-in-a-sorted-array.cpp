class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref (n,0);
        vector<int> suff (n,0);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1, j = n-2; i<n; i++ , j--) {
            pref[i] = pref[i-1] + nums[i];
            suff[j] = suff[j+1] + nums[j];
        }

        vector<int> res(n);

        for(int i = 0; i<n; i++) {
            int left = abs((nums[i] * (i+1)) - pref[i]);
            int right = abs((nums[i] * (n - i)) - suff[i]);
            res[i] = left + right;
        }

        return res;
    }
};