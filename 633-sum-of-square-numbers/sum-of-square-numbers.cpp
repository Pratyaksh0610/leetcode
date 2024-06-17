#define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll si = 0, ei = sqrt(c)+1;

        while (si <= ei) {
            // ll mid = si + (ei - si) / 2;
            ll rem = c - pow(si, 2);
            if (rem >= 0) {
                ll root=sqrt(rem);
                if(pow(root,2)==rem){
                    return true;
                }
            }
            si++;
        }
        return false;
    }
};