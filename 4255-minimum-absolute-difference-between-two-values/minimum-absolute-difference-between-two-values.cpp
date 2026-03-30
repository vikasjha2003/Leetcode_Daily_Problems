class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int res = n+1;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0) continue;
            else if (nums[i] == 1) {
                int j = i+1;
                while(j<n && nums[j] != 2) j++;
                if(j<n) res = min(res,abs(i-j));
            } else {
                int j = i+1;
                while(j<n && nums[j] != 1) j++;
                if(j<n) res = min(res,abs(i-j));
            }
        }
        if(res == n+1) return -1;
        return res;
    }
};