#define ll long long int
class Solution {
    private:
    bool fun(vector<int>& p, ll m,ll val,set<int>&s){
        ll st=p[0]+val;
        m--;
        while(m>0){
            auto it=s.lower_bound(st);
            if(it==s.end()){
                return false;
            }
            m--;
            st=(*it)+val;
        }
        return true;
    }
public:
    int maxDistance(vector<int>& p, int m) {
        //b.s
        sort(p.begin(),p.end());
        ll si=1,ei=1e9,ans=0;
        set<int>s;
        for(int i=0;i<p.size();i++){
            s.insert(p[i]);
        }
        while(si<=ei){
            ll mid=si+(ei-si)/2;
            bool ch=fun(p,m,mid,s);
            if(ch){
                // cout<<mid<<endl;
                ans=mid;
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        return ans;
    }
};