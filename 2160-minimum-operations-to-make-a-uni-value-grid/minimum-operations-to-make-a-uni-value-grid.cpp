class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums; // sorting grid won't sort elements but rows instead
        for(int i = 0; i<m; i++) {
            for(int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());

        int median = nums[(m*n) / 2];
        int res = 0;

        for(int i = 0; i<m*n; i++) {
            int cur = abs(median - nums[i]);
            if(cur % x != 0) return -1;
            res += cur / x;
        }

        return res;
    }
};