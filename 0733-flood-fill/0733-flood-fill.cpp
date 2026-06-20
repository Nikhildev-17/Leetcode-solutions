class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int originalColor, int n, int m, int color){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        if(image[i][j] != originalColor) return;

        image[i][j] = color;

        dfs(i - 1, j, image, originalColor, n, m, color);
        dfs(i, j + 1, image, originalColor, n, m, color);
        dfs(i + 1, j, image, originalColor, n, m, color);
        dfs(i, j - 1, image, originalColor, n, m, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();

        if(originalColor == color) return image;

        dfs(sr, sc, image, originalColor, n, m, color);

        return image;
    }
};