class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        int ans=0;
        int curr=0;
        int p=power,n=t.size();
        sort(t.begin(),t.end());
        int i=0,j=n-1;
        while(i<=j){
            if(t[i]<=p){
                curr++;
                p-=t[i];
                i++;
            }
            else{
                if(curr<=0){
                    break;
                }
                curr--;
                p+=t[j];
                j--;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};