class Solution {
    private:
    int fun(vector<string>&d,string &nums,bool tight,int ind,vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        else if(dp[tight][ind]!=-1){
            // cout<<ind<<" "<<tight<<endl;
            return dp[tight][ind];
        }
        if(ind==nums.size()-1){
            int ans=0;
            // cout<<ind<<" "<<tight<<endl;
            if(tight){
                int i=0;
                for(;i<d.size();i++){
                    if(d[i][0]-'0'>nums[ind]-'0'){
                        break;
                    }
                }
                // cout<<i<<endl;
                ans+=i;
            }
            else{
                ans+=d.size();
            }
            return dp[tight][ind]= ans;
        }
        int ans=0;
        if(tight){
            ans+=fun(d,nums,false,ind+1,dp);
            bool finisher=true;
            for(int i=0;i<d.size();i++){
                if(d[i][0]-'0'<nums[ind]-'0'){
                    // cout<<"1 mil gya"<<endl;
                    // finisher=false;
                    ans+=fun(d,nums,false,ind+1,dp);
                }
                else if(d[i][0]-'0'==nums[ind]-'0'){
                    finisher=false;
                    ans+=fun(d,nums,true,ind+1,dp);
                }
            }
            if(finisher){
                for(int i=ind+2;i<nums.size();i++){
                    ans+=fun(d,nums,false,i,dp);
                }
            }
        }
        if(tight==false){
            for(int i=0;i<d.size();i++){
                ans+=fun(d,nums,false,ind+1,dp);
            }
        }
        return dp[tight][ind]= ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string nums=to_string(n);
        vector<vector<int>>dp(2,vector<int>(nums.size()+1,-1));
        return fun(digits,nums,true,0,dp);
    }
};