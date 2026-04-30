class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto &vec : grid) {
            for(auto &it : vec) {
                nums.push_back(it);
            }
        }

        sort(nums.begin(),nums.end());

        int median = nums[nums.size() / 2];
        int res = 0;

        for(auto &it : nums) {
            int cur = abs(median - it);
            if(cur % x != 0) return -1;
            res += cur / x;
        }

        return res;
    }
};