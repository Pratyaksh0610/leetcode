class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();
        for(int i=0;i<r;i++){
            for(int j=i;j<c;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        for(int i=0;i<r;i++){
            reverse(m[i].begin(),m[i].end());
        }
        // return m;
    }
};