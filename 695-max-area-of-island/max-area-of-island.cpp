class Solution {
public:
    int m , n;
    int DFS (vector<vector<int>>& grid , vector<vector<bool>>& visited , int row , int col) {
        if(row < 0 || col < 0 || row == m || col == n || visited[row][col] == true || grid[row][col] == 0) return 0;
        visited[row][col] = true;
        int a = DFS(grid,visited,row+1,col);
        int b = DFS(grid,visited,row-1,col);
        int c = DFS(grid,visited,row,col+1);
        int d = DFS(grid,visited,row,col-1);
        return 1 + a + b + c + d;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited (m , vector<bool> (n,false));
        int maxi = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                maxi = max(maxi,DFS(grid,visited,i,j));
            }
        }
        return maxi;
    }
};