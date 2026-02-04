class Solution {
public:
    int m , n;
    void DFS(vector<pair<int,int>>& collection , vector<vector<char>>& board , vector<vector<bool>> &visited, bool &flag, int row , int col) {

        if(row < 0 || col < 0 || row == m || col == n || visited[row][col] == true || board[row][col] == 'X') return;

        visited[row][col] = true;
        collection.push_back({row,col});

        if(row + 1 == m || col + 1 == n || row - 1 < 0 || col - 1 < 0) flag = true;

        DFS(collection,board,visited,flag,row + 1,col);
        DFS(collection,board,visited,flag,row - 1,col);
        DFS(collection,board,visited,flag,row,col + 1);
        DFS(collection,board,visited,flag,row,col - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited (m,vector<bool> (n,false));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 'O' && visited[i][j] == false) {
                    vector<pair<int,int>> collect;
                    bool flag = false;
                    DFS(collect,board,visited,flag,i,j);
                    if(!flag) {
                        for(auto &it : collect) {
                            board[it.first][it.second] = 'X';
                        }
                    }
                }
            }
        }
    }

};