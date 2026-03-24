class Solution {
public:
    int n;
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        long long prev_even = 0, prev_odd = 0;
        long long cur_even = 0, cur_odd = 0;
        for(int i = 0; i < n; i++) {
            cur_odd = max(prev_odd,prev_even - nums[i]);
            cur_even = max(prev_even,prev_odd + nums[i]);
            prev_odd = cur_odd;
            prev_even = cur_even;
        }
        return max(cur_even,cur_odd);
    }
    
};