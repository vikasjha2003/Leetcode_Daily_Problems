class Solution {
public:
    void DFS (vector<vector<int>>& image, int row, int col, int &color, int &key) {
        if(row < 0 || row == image.size() || col < 0 || col == image[0].size() || image[row][col] != key || image[row][col] == color) return;
        image[row][col] = color;
        DFS(image, row + 1, col, color, key);
        DFS(image, row - 1, col, color, key);
        DFS(image, row, col + 1, color, key);
        DFS(image, row, col - 1, color, key);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int a = image[sr][sc];
        DFS(image,sr,sc,color,a);
        return image;
    }
};