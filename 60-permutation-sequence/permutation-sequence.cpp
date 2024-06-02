class Solution {
    private:
    int fact(int n){
        if(n==1||n==0){
            return 1;
        }
        return n*fact(n-1);
    }
public:
    string getPermutation(int n, int k) {
        int rem=k;
        set<int>ss;
        for(int i=1;i<=n;i++){
            ss.insert(i);
        }
        string s;
        while(rem>1){//rem=6
            int val=fact(n);//6
            int freq=val/n;//2
            n--;//2

            int cnt=1;
            while((freq*cnt)<rem){
                cnt++;//3
            }
            int number=-1;
            int cc=cnt;
            for(auto it:ss){
                cnt--;
                if(cnt==0){
                    number=it;//3
                    break;
                }
            }
            s=s+(to_string(number));
            ss.erase(number);
            rem-=(freq*(cc-1));
        }
        for(auto it:ss){
            s=s+to_string(it);
        }
        return s;
    }
};