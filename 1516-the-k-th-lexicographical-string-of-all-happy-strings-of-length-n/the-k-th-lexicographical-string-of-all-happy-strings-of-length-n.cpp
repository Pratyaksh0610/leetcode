class Solution {
    string fun(int n, int k, int prev) {
        string ans = "";
        if(n==0){
            return ans;
        }
        // cout<<"n: "<<n<<" k: "<<k<<" prev: "<<prev<<endl;
        int subTot = pow(2, n - 1);
        int letter = k / subTot;
        k = k % subTot;
        char l='d';
        if(letter==0){
            l= 'a';
            if(prev==0){
                l='b';
            }
        }
        else if(letter==1){
            l='c';
            if(prev==2){
                l='b';
            }
        }
        return ans + l + fun(n - 1, k, l-'a');
    }

public:
    string getHappyString(int n, int k) {
        int subTot=pow(2,n-1);
        int tot = 3 * subTot;
        if (k-- > tot) {
            return "";
        }
        char l= 'a'+ k/subTot;
        int st=k/subTot;
        k = k % subTot;
        string ans= l+ fun(n-1, k, st);
        return ans;
    }
};