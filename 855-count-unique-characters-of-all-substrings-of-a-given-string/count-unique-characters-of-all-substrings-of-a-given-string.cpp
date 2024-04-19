class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size(),ans=0;
        unordered_map<char,int>m,p;
        vector<int>next(n,-1),prev(n,-1);
        for(int i=n-1;i>=0;i--){
            if(m.find(s[i])!=m.end()){
                next[i]=m[s[i]];
            }
            m[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(p.find(s[i])!=p.end()){
                prev[i]=p[s[i]];
            }
            p[s[i]]=i;
        }

        // for(int i=0;i<n;i++){
        //     cout<<next[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<prev[i]<<" ";
        // }

        for(int i=0;i<n;i++){
            // int val=0;
            // if(prev[i]==-1){
            //     val+=i+1;
            // }
            // else{
            //     val+=i-prev[i];
            // }

            // if(next[i]==-1){
            //     val+=n-i-1;
            // }
            // else{
            //     val+=next[i]-prev[i];
            // }
            // cout<<s[i]<<" "<<val<<endl;
            int pval=prev[i];
            int nval=next[i]-i;
            if(nval<0){
                nval=n-i;
            }
            ans+=(i-pval)*(nval);
            // ans+=val;
        }
        return ans;
    }
};