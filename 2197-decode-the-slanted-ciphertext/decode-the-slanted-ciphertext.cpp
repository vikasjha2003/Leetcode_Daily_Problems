class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.length() == 0) return "";
        int col = encodedText.length() / rows;
        vector<vector<char>> mat (rows, vector<char> (col));
        int k = 0;
        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<col; j++) {
                mat[i][j] = encodedText[k];
                k++;
            }
        }
        string res = "";
        for(int i = 0; i<col; i++) {
            k = i;
            for(int j = 0; j<rows; j++) {
                if(k == col) break;
                res.push_back(mat[j][k]);
                k++;
            }
        }
        while(true) {
            char c = res.back();
            if (c == ' ') res.pop_back();
            else break;
        }
        return res;
    }
};