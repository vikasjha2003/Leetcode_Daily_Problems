class Solution {

    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length, n = boxGrid[0].length;

        char[][] box = new char[n][m];

        for(int i = 0; i<m; i++) {
            int r = n-1;
            for(int l = n-1; l>= 0; l--) {
                if(boxGrid[i][l] == '#') {
                    boxGrid[i][l] = '.';
                    boxGrid[i][r] = '#';
                    r--;
                }
                if (boxGrid[i][l] == '*') {
                    r = l-1;
                }
            }
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                box[j][m-i-1] = boxGrid[i][j];
            }
        }

        return box;        
    }
}