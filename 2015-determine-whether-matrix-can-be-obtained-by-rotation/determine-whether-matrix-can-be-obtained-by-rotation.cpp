class Solution {
public:
    bool isequal (vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i<mat.size(); i++) {
            for(int j = 0; j<mat.size(); j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0; i<n; i++) {
            int k = 0;
            for(int j = n-1; j>=0; j--) {
                if(k<=j){
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][j];
                    matrix[i][j] = temp;
                    k++;
                }
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 1; i<=3; i++) {
            if(isequal(mat,target)) return true;
            else rotate(mat);
        }
        if(isequal(mat,target)) return true;
        else return false;
    }
};