class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++) {
            int row_sum = 0;
            for(int j = 0; j<grid[0].size(); j++) {
                row_sum += grid[i][j];
                if(i > 0) grid[i][j] = grid[i-1][j] + row_sum;
                else grid[i][j] = row_sum;
                if (grid[i][j] <= k) count++;
            }
        }
        return count;
    }
};