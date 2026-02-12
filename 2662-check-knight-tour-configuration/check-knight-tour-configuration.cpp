class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        int n = grid.size();
        int drow[8] = {2,2,1,1,-1,-1,-2,-2};
        int dcol[8] = {1,-1,2,-2,2,-2,1,-1};
        int row = 0;
        int col = 0;
        for(int i = 1; i< n*n; i++) {
            bool flag = false;
            for(int j = 0; j<8; j++) {
                int nr = row + drow[j];
                int nc = col + dcol[j];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != i) continue;
                row = nr;
                col = nc;
                flag = true;
                break;
            }
            if(!flag) return false;
        }
        return true;  
    }
};