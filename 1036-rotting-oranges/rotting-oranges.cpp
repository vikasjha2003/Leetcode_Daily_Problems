class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        int cnt = -1;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {-1,0,1,0};
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto it = q.front();
                q.pop();
                for(int i = 0; i<4; i++) {
                    int row = it.first + delrow[i];
                    int col = it.second + delcol[i];
                    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) continue;
                    if(grid[row][col] == 1) {
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row,col});
                    }
                }
            }
            cnt++;
        }
        if(fresh > 0) return -1;
        return cnt;
    }
};