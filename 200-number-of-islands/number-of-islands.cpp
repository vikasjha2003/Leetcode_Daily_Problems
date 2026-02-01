class Solution {
public:
    void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row , int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(grid[row][col] == '1' && visited[row][col] == false) {
            visited[row][col] = true;
            visit(grid,visited,row - 1,col);
            visit(grid,visited,row + 1,col );
            visit(grid,visited,row ,col - 1);
            visit(grid,visited,row ,col + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited (m , vector<bool> (n,false));
        int cnt = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    cnt++;
                    visit(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};