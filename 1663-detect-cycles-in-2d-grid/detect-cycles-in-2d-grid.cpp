class Solution {
public:
    int m , n;

    bool BFS (vector<vector<char>>& grid, vector<vector<bool>>& visited, int &row, int &col) {
        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{row,col},{-1,-1}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int &row = it.first.first;
            int &col = it.first.second;
            int &pr = it.second.first;
            int &pc = it.second.second; 

            for(int i = 0; i<4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr <0 || nr == m || nc < 0 || nc == n) continue;

                if(visited[nr][nc] && grid[nr][nc] == grid[row][col] 
                && nr != pr && nc != pc) return true;

                if(visited[nr][nc] || grid[nr][nc] != grid[row][col]) continue;

                visited[nr][nc] = true;
                q.push({{nr,nc},{row,col}});                
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited (m , vector<bool> (n , false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!visited[i][j]) {
                    visited[i][j] = true;
                    if(BFS(grid,visited,i,j)) return true;
                }
            }
        }

        return false;
    }
};