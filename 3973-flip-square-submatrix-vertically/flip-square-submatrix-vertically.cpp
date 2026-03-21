class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y; i < y+k; i++) {
            int u = x;
            int b = x+k-1;
            while(u<b) {
                swap(grid[u][i],grid[b][i]);
                u++;
                b--;
            }
        }
        return grid;
    }
};