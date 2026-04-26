class Solution {
public:
    int m , n;
    int drow[4] = {0,0,1,-1};
    int dcol[4] = {1,-1,0,0};

    bool DFS (vector<vector<char>>& grid, vector<vector<bool>>& visited, int &row, int &col, int &pr , int &pc) {
        visited[row][col] = true;

        for(int i = 0; i<4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if(nr <0 || nr == m || nc < 0 || nc == n) continue;

            if(grid[nr][nc] != grid[row][col] || (nr == pr && nc == pc)) continue;

            if(visited[nr][nc]) return true;

            if(DFS(grid,visited,nr,nc,row,col)) return true;
            
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited (m , vector<bool> (n , false));
        int pr = -1, pc = -1;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!visited[i][j]) {
                    if(DFS(grid,visited,i,j,pr,pc)) return true;
                }
            }
        }

        return false;
    }
};