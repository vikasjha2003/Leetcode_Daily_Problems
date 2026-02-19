class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += mat[i][i];
        }
        int i = 0, j = n-1;
        while(j>=0) {
            if(i != j) {
                sum += mat[i][j];
            }
            i++;
            j--;
        }
        return sum;
    }
};