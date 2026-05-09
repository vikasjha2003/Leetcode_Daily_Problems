class Solution {
    public static List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;

        int rows = 0, rowe = m-1, cols = 0, cole = n-1;


        List<Integer> arr = new ArrayList<>(); 

        while(rows <= rowe && cols <= cole) {
            for(int i = cols; i <= cole; i++) {
                arr.add(matrix[rows][i]);
            }
            rows++;
            for(int i = rows; i <= rowe; i++) {
                arr.add(matrix[i][cole]);
            }
            cole--;
            if(rows <= rowe) {
                for(int i = cole; i >= cols; i--) {
                    arr.add(matrix[rowe][i]);
                }
                rowe--;
            }
            if(cols <= cole) {
                for(int i = rowe; i >= rows; i--) {
                    arr.add(matrix[i][cols]);
                }
                cols++;
            }
        }

        return arr;
    }
}