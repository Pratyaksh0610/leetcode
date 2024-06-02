class Solution {
private:
    bool rowCheck(vector<vector<char>>& b, int i, char ch) {
        if (i < 0 || i >= 9)
            return false;
        for (int j = 0; j < 9; j++) {
            if (b[i][j] == ch) {
                return false;
            }
        }
        return true;
    }
    bool colCheck(vector<vector<char>>& b, int i, char ch) {
        if (i < 0 || i >= 9)
            return false;
        for (int j = 0; j < 9; j++) {
            if (b[j][i] == ch) {
                return false;
            }
        }
        return true;
    }
    bool boxCheck(vector<vector<char>>& b, int i, int j, char ch) {
        if (i < 0 || i >= 9 || j < 0 || j >= 9)
            return false;

        int limr = 3*(i / 3) + 3, limc = 3*(j / 3) + 3;
        for (int sr = (i / 3)*3; sr < limr; sr++) {
            for (int sc = 3*(j / 3); sc < limc; sc++) {
                if (b[sr][sc] == ch) {
                    return false;
                }
            }
        }
        return true;
    }

    bool fun(vector<vector<char>>& b, int r, int c) {
        if (r >=9) {
            // cout<<"SOLVED"<<endl;
            return true;
        } else if (c == 9) {
            return fun(b, r + 1, 0);
        } else if (b[r][c] != '.') {
            return fun(b, r, c + 1);
        }

        bool done = false;
        
        for (int i = 1; i <= 9; i++) {
            char ch = '0' + i;
            bool check = rowCheck(b, r, ch) && colCheck(b, c, ch) &&
                         boxCheck(b, r, c, ch);
            if (check) {
                b[r][c] = ch;
                bool val= fun(b, r, c + 1);
                if (val) {
                    return val;
                }
                b[r][c] = '.';
            }
        }
        return done;
    }

public:
    void solveSudoku(vector<vector<char>>& b) {
        fun(b, 0, 0);
    }
};