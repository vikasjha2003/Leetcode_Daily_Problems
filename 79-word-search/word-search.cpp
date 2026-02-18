class Solution {
public:
    int n , m, w;
    int drow[4] = {0,0,1,-1};
    int dcol[4] = {1,-1,0,0}; 
    bool DFS (vector<vector<char>>& board, vector<vector<bool>> &visited, 
    string &word, int idx, int row , int col) {
        if(idx == w-1) return true;
        visited[row][col] = true;
        for(int i = 0; i<4; i++) {         
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n || visited[nr][nc] == true
             || board[nr][nc] != word[idx+1]) continue;
            if(DFS(board,visited,word,idx+1,nr,nc) == true) return true;
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        w = word.size();
        vector<vector<bool>> visited (m, vector<bool> (n,false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(DFS(board,visited,word,0,i,j)) return true;
                }
            }
        }
        return false;
    }
};