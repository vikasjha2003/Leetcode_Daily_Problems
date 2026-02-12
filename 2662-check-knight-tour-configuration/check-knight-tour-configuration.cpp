class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        int n = grid.size();
        int drow[8] = {2,2,1,1,-1,-1,-2,-2};
        int dcol[8] = {1,-1,2,-2,2,-2,1,-1};
        queue<pair<int,int>> q;
        q.push({0,0});
        for(int i = 1; i< n*n; i++) {
            auto it = q.front();
            q.pop();
            for(int j = 0; j<8; j++) {
                int row = it.first + drow[j];
                int col = it.second + dcol[j];
                if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != i) continue;
                q.push({row,col});
                break;
            }
            if(q.empty()) return false;
        }
        return true;  
    }
};