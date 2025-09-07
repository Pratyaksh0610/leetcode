#define ll long long int
class Solution {
public:
    int uniquePaths(int m, int n) {
        int tot=m+n-2;
        int mini=min(m,n)-1;
        ll ans=1;
        for(int i=0;i<mini;i++){
            ans=(ans*(tot-i))/(i+1);
        }
        return ans;
    }
};