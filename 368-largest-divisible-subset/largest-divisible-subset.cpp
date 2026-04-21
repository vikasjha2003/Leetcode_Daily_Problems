class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> prev(n,-1); // to store last element
        vector<int> dp(n,1); // to store length
        int idx = 0;

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > dp[idx]) idx = i;
        }

        vector<int> res;
        while(idx != -1) {
            res.push_back(nums[idx]);
            idx = prev[idx];
        }

        return res;
    }
};