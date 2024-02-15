class Solution {
    private:
    void fun(int i,int j,vector<vector<int>>& m){
        vector<int>temp;
        int ii=i,jj=j;
        int r=m.size(),c=m[0].size();
        while(ii<r&&jj<c){
            temp.push_back(m[ii++][jj++]);
        }
        sort(temp.begin(),temp.end());
        ii=i,jj=j;
        int k=0;
        while(ii<r&&jj<c&&k<temp.size()){
            m[ii++][jj++]=temp[k++];
        }
        return;
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& m) {
        //inc row by 1 & col by 1
        int r=m.size(),c=m[0].size();
        for(int i=0;i<c;i++){
            fun(0,i,m);
        }
        for(int i=1;i<r;i++){
            fun(i,0,m);
        }
        return m;
    }
};