class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        bool flag = true;
        for(int i = 0; i<n; i++) {
            if(i > 0 && i < n-1 && nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                flag = false;
                continue;
            }
            if(flag) sum += nums[i];
            else sum -= nums[i];
        }
        if(sum == 0) return -1;
        if(sum > 0) return 0;
        return 1;
    }
};