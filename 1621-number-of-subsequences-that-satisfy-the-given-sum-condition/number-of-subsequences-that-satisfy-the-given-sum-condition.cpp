class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        vector<int> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        int count = 0;
        for(int i = 0; i<n; i++) {
            int lo = i;
            int hi = n -1;
            while(lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if(nums[i] + nums[mid] <= target) lo = mid+1;
                else hi = mid-1;
            }
            if(hi < i) continue;
            count = (count + pow2[hi-i]) % MOD;
        }
        return count;
    }
};