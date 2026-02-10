class Solution {
public:
    int m , n;
    void DFS (const vector<vector<int>> &grid, vector<vector<int>> &res, vector<vector<bool>> &visited, int row , int col , const int &color, const int &component) {
        if(row < 0 || col < 0 || row == m || col == n || visited[row][col] || grid[row][col] != component) return;
        visited[row][col] = true;
        if(row == 0 || col == 0 || row == m-1 || col == n-1 || grid[row+1][col] != component || grid[row-1][col] != component || grid[row][col+1] != component || grid[row][col-1] != component) res[row][col] = color; // boundary and border
        DFS(grid,res,visited,row+1,col,color,component);
        DFS(grid,res,visited,row-1,col,color,component);
        DFS(grid,res,visited,row,col+1,color,component);
        DFS(grid,res,visited,row,col-1,color,component);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n,false));
        vector<vector<int>> res (grid.begin(),grid.end());
        DFS(grid,res,visited,row,col,color,grid[row][col]);
        return res;
    }
};