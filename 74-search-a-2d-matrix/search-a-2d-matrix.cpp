class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r=m.size(),c=m[0].size();
        int i=r-1,j=0;
        while(i>=0&&j<c){
            if(m[i][j]==target){
                return true;
            }
            else if(m[i][j]>target){
                i--;
            }
            else{
                j++;
            }
        }
        return false;
    }
};