class Solution {
public:
    int m , n;
    void DFS(vector<vector<int>> &grid , vector<vector<bool>> &visited , bool & flag, int & count , int row , int col) {
        if(row < 0 || row == m || col < 0 || col == n || grid[row][col] == 0 || visited[row][col]) return;
        visited[row][col] = true;
        count++;
        if(row - 1 < 0 || row + 1 == m || col - 1 < 0 || col + 1 == n) flag = true;
        DFS(grid,visited,flag,count,row+1,col);
        DFS(grid,visited,flag,count,row-1,col);
        DFS(grid,visited,flag,count,row,col+1);
        DFS(grid,visited,flag,count,row,col-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited (m , vector<bool> (n , false));
        int total = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    int cur = 0;
                    bool flag = false;
                    DFS(grid,visited,flag,cur,i,j);
                    if(!flag) total += cur;
                }
            }
        }
        return total;
    }
};