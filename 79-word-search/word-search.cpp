#define pi pair<int, int>
class Solution {
    bool fun(int i, int j, vector<vector<char>>& b, string& w,int ind,
             vector<vector<int>>& vis) {
        if (ind >= w.size()) {
            return true;
        }
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        bool done=false;
        for(int k=0;k<4;k++){
            int ii=i+row[k],jj=j+col[k];
            if(ii<0||ii>=b.size()||jj<0||jj>=b[0].size()||vis[ii][jj]==1||b[ii][jj]!=w[ind]){
                continue;
            }
            vis[ii][jj]=1;
            done=done|fun(ii,jj,b,w,ind+1,vis);
            vis[ii][jj]=0;
        }
        return done;
    }

public:
    bool exist(vector<vector<char>>& b, string w) {
        int r = b.size(), c = b[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        // int curr = 1;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (b[i][j] == w[0]) {
                    // cout<<i<<" "<<j<<endl;
                    vis[i][j]=1;
                    bool ans = fun(i, j, b, w,1, vis);
                    vis[i][j]=0;
                    // curr++;
                    if (ans) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};