#define ll long long int
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        ll range=(ll)right-(ll)left+1;
        ll val=0;
        for(int i=1;i<=31;i++){
            ll span=pow(2,i),ones=span/2;
            if(ones<range){
                continue;
            }
            ll lower=(ll)left/span;
            ll l=(ll)left-(lower*span),r=(ll)right-(lower*span);
            if(l>=ones&&r<ones*(ll)2){
                val=val|(1<<(i-1));
            }
        }
        return val;
    }
};