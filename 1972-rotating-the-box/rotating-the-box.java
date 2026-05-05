class Solution {

    public char[][] rotateTheBox(char[][] boxGrid) {
        int m = boxGrid.length, n = boxGrid[0].length;

        char[][] box = new char[n][m];

        for(int i = 0; i<m; i++) {
            int l = n-1;
            int r = n-1;
            while(l >= 0) {
                if(boxGrid[i][l] == '#') {
                    char temp = boxGrid[i][r];
                    boxGrid[i][r] = boxGrid[i][l];
                    boxGrid[i][l] = temp;
                    r--;
                }
                if (boxGrid[i][l] == '*') {
                    r = l-1;
                }
                l--;
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