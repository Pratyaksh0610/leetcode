class Solution {
private:
    int fun(int i, int j, vector<vector<int>>& m) {
        int ii = i, jj = j, r = m.size(), c = m[0].size();
        int si = 1, ei = 300;
        int ans = 1;
        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            bool done = true;
            for (int ii = i; ii < i + mid; ii++) {
                for (int jj = j; jj < j + mid; jj++) {
                    if (ii >= r || jj >= c || m[ii][jj] == 0) {
                        done = false;
                        break;
                    }
                }
                if (done == false) {
                    break;
                }
            }
            if (done) {
                ans = mid;
                si = mid + 1;
            } else {
                ei = mid - 1;
            }
        }
        return ans;
    }

public:
    int countSquares(vector<vector<int>>& m) {
        int r = m.size(), c = m[0].size();
        int ans = 0;
        cout<<m.size()<<" "<<m[0].size()<<endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == 1) {
                    int lim = fun(i, j, m);
                    // cout << i << " " << j << " " << lim<<endl;
                    ans += lim;
                }
            }
        }
        return ans;
    }
};