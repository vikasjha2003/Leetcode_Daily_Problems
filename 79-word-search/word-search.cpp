class Solution {
public:
    int n , m;
    int drow[4] = {0,0,1,-1};
    int dcol[4] = {1,-1,0,0}; 
    bool DFS (vector<vector<char>>& board, string &word, int idx, int row , int col) {
        if(idx == word.length()-1) return true;
        board[row][col] = '0';
        for(int i = 0; i<4; i++) {         
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n
            || board[nr][nc] != word[idx+1]) continue;
            if(DFS(board,word,idx+1,nr,nc)) return true;
        }
        board[row][col] = word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0]) {
                    if(DFS(board,word,0,i,j)) return true;
                }
            }
        }
        return false;
    }
};