class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r=m.size(),c=m[0].size();
        int si=0,ei=r*c-1;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            int rnum=mid/c;
            int cnum=mid%c;
            int val=m[rnum][cnum];
            if(val==target){
                return true;
            }
            else if(val>target){
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return false;
    }
};