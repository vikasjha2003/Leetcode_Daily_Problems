class Solution {
public:
    int m , n;
    void DFS(const vector<vector<int>> &grid,
            vector<vector<int>> &res,
            vector<vector<bool>> &visited,
            int row, int col,
            const int &color,
            const int &component) {

        if(row < 0 || col < 0 || row == m || col == n ||
        visited[row][col] || grid[row][col] != component)
            return;

        visited[row][col] = true;

        bool isBorder = false;
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

        for(int d = 0; d < 4; d++) {
            int nr = row + drow[d];
            int nc = col + dcol[d];
            if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != component) {
                isBorder = true;
            }
            DFS(grid, res, visited, nr, nc, color, component);
        }
        if(isBorder) res[row][col] = color;
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