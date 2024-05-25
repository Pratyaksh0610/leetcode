#define ll long long int
class Solution {
    // int fun(int i,int j)
public:
    int uniquePaths(int m, int n) {
        int tot=m+n-2;
        int d=m-1,r=n-1;
        //val=fact(tot)/(fact(d)*fact(r));
        //min(d,r);
        int mini=min(d,r);
        ll val=1;
        for(int i=0;i<mini;i++){
            val=(val*(tot-i))/(i+1);
        }
        return val;
    }
};