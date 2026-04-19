class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid (n, vector<int> (m,0));
        sort(sources.begin(), sources.end(), [] (auto &v1, auto &v2) {
            return v1[2] > v2[2];
        });

        queue<vector<int>> q;
        for(auto &s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.push(s);
        }

        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            for(int i = 0; i<4; i++) {
                int row = it[0] + drow[i];
                int col = it[1] + dcol[i];

                if(row < 0 || row == n || col < 0 || col == m || grid[row][col]) continue;

                grid[row][col] = it[2];

                q.push({row,col,it[2]});
            }
        }
        
        return grid;
    }
};