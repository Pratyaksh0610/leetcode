class Solution {
    // check row
    // check col
    // check subBox
    bool rowCheck(vector<vector<char>>& sudoku, int index) {
        int row = index / 9;
        int col = index % 9;
        char ch = sudoku[row][col];
        for (int i = 0; i < 9; i++) {
            if (sudoku[row][i] == ch && i != col) {
                return false;
            }
        }
        return true;
    }
    bool colCheck(vector<vector<char>>& sudoku, int index) {
        int row = index / 9;
        int col = index % 9;
        char ch = sudoku[row][col];
        for (int i = 0; i < 9; i++) {
            if (sudoku[i][col] == ch && i != row) {
                return false;
            }
        }
        return true;
    }
    bool subBoxCheck(vector<vector<char>>& sudoku, int index) {
        int row = index / 9;
        int col = index % 9;
        int box = 3 * (row / 3) + (col / 3);
        char ch = sudoku[row][col];
        vector<int> cnt(10, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (sudoku[3 * (box / 3) + i][3 * (box % 3) + j] == '.') {
                    continue;
                }
                int cntIndex =
                    sudoku[3 * (box / 3) + i][3 * (box % 3) + j] - '0';
                // cout<<cntIndex<<endl;
                cnt[cntIndex]++;
                if (cnt[cntIndex] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& sudoku, int index) {
        bool isValid = true;
        isValid = rowCheck(sudoku, index);
        if (isValid) {
            isValid = colCheck(sudoku, index);
        }
        if (isValid) {
            isValid = subBoxCheck(sudoku, index);
        }
        return isValid;
    }

    bool move(vector<vector<char>>& board, 
              int index) {
        int row = index / 9;
        int col = index % 9;
        // cout<<row<<" "<<col<<endl;
        if (index >= 81) {
            // board = temp;
            return true;
        }
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i++) {
                board[row][col] = '0' + i;
                bool check = isValidSudoku(board, index);
                if (check) {
                    bool completed = move(board, index + 1);
                    if (completed) {
                        return true;
                    }
                }
                board[row][col] = '.';
            }
            if(board[row][col]=='.'){
                return false;
            }
        }
        // bool check = isValidSudoku(board, index);
        // if (check) {
            return move(board, index + 1);
            // if (completed) {
                // return true;
            // }
        // }
        // return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // vector<vector<char>> temp = board;
        move(board, 0);
    }
};