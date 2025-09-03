class Solution {
    double fun(double x, int n) {
        // cout<<x<<" "<<n<<endl;
        if (n == 1) {
            return x;
        } else if (n == -1) {
            double ans=(double)1 / (double)x;
            // cout<<"MILA "<<ans<<endl;
            return ans;
        } else if (n == 0) {
            return 1;
        }
        double val = fun(x, n / 2);
        val *= val;
        // cout<<"asli value"<<val<<endl;
        if (n % 2 == 1||n%2==-1) {
            if (n < 0) {
                val = val * ((double)1 / (double)x);
            } else {
                val = val * x;
            }
        }
        return val;
    }

public:
    double myPow(double x, int n) { return fun(x, n); }
};