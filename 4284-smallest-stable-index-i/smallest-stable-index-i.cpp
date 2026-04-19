class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref (n,0);
        pref[0] = nums[0];

        for(int i = 1; i<n; i++) {
            pref[i] = max(nums[i], pref[i-1]);
        }

        int mini = nums[n-1];
        int res = -1;

        for(int i = n-1; i >= 0; i--) {
            if(mini > nums[i]) {
                mini = nums[i];
            }
            pref[i] -= mini;
            if(pref[i] <= k) res = i;
        }

        return res;
    }
};