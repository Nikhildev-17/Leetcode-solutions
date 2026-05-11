class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for(int j=0; j<9; j++){  // column wise
            if(board[row][j] == dig){
                return false;
            }
        }
        for(int i=0; i<9; i++){  // row wise
            if(board[i][col] == dig){
                return false;
            }
        }
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for(int i=sr; i<=sr+2; i++){
            for(int j=sc; j<=sc + 2; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;        
        
    }
    bool sudokuSolver(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }

        int nextRow = row;
        int nextCol = col + 1;
        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){
            return sudokuSolver(board, nextRow, nextCol);
        }

        for(int digit = 1; digit <= 9; digit++){
            if(isSafe(board, row, col, digit + '0')){
                board[row][col] = digit + '0';
                if(sudokuSolver(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';

            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0,0);
    }
};