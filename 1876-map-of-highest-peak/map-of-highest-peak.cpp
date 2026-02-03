class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res (m, vector<int> (n,0));
        vector<vector<bool>> visited (m, vector<bool> (n,false));
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(mat[i][j] == 1) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        } 
        int cnt = 0;
        while(!q.empty()) {
            int a = q.size();
            cnt++;
            while(a--) {
                auto it = q.front();
                q.pop();
                for(int i = 0; i<4; i++) {
                    int row = it.first + drow[i];
                    int col = it.second + dcol[i];
                    if(row < 0 || col < 0 || row == m || col == n || visited[row][col]) {
                        continue;
                    }
                    res[row][col] = cnt;
                    visited[row][col] = true;
                    q.push({row,col});
                }
            }
        }
        return res;
    }
};