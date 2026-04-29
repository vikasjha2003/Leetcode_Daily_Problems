class Solution {
public:
    pair<int,int> travel[7][2] = {
        {{0,0},{0,0}} ,
        {{0,-1},{0,1}} , 
        {{-1,0},{1,0}} , 
        {{0,-1},{1,0}} ,
        {{1,0},{0,1}} ,
        {{0,-1},{-1,0}} ,
        {{-1,0},{0,1}}
    };

    int m , n;

    bool DFS (vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        if(row == m-1 && col == n-1) return true;

        visited[row][col] = 1;

        for(auto &it : travel[grid[row][col]]) {
            int nr = row + it.first;
            int nc = col + it.second;

            if(nr < 0 || nr == m || nc < 0 || nc == n || visited[nr][nc] == 1)
                continue;
            
            for(auto &q : travel[grid[nr][nc]]) {
                if(nr + q.first == row && nc + q.second == col) {
                    if (DFS(grid,visited,nr,nc)) return true;
                }
            }

        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited (m, vector<int> (n,0));

        return DFS(grid,visited,0,0);
    }
};