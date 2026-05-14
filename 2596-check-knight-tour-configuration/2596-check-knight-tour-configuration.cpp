class Solution {
public:
    int knightsTour(vector<vector<int>>& grid, int row, int col, int n, int expValue){
        if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != expValue){
            return false;
        }

        if(expValue == n * n - 1){
            return true;
        }


        bool ans1 = knightsTour(grid, row-2, col + 1, n, expValue + 1);
        bool ans2 = knightsTour(grid, row-2, col - 1, n, expValue + 1);
        bool ans3 = knightsTour(grid, row-1, col - 2, n, expValue + 1);
        bool ans4 = knightsTour(grid, row-1, col + 2, n, expValue + 1);
        bool ans5 = knightsTour(grid, row+1, col - 2, n, expValue + 1);
        bool ans6 = knightsTour(grid, row+1, col + 2, n, expValue + 1);
        bool ans7 = knightsTour(grid, row+2, col - 1, n, expValue + 1);
        bool ans8 = knightsTour(grid, row+2, col + 1, n, expValue + 1);
        
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int row = grid.size();

        return knightsTour(grid, 0, 0, row, 0);
    }
};