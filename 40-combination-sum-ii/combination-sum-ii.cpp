class Solution {
    void fun(vector<vector<int>>&ans,vector<int>&temp,vector<int>&c,int index,int t){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        else if(index>=c.size()||t<0){
            return;
        }
        // t-=c[index];
        for(int i=index;i<c.size();i++){
            if(i==index+1){
                temp.push_back(c[i]);
                fun(ans,temp,c,i,t-c[i]);
                temp.pop_back();
            }
            else if(i>index+1 && c[i]!=c[i-1]){
                temp.push_back(c[i]);
                fun(ans,temp,c,i,t-c[i]);
                temp.pop_back();
            }
        }
        return;

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>>ans;
        sort(c.begin(),c.end());
        vector<int>temp;
        temp.push_back(c[0]);
        fun(ans,temp,c,0,t-c[0]);
        temp.pop_back();
        for(int i=1;i<c.size();i++){
            if(i!=0&&c[i]!=c[i-1]){
                temp.push_back(c[i]);
                fun(ans,temp,c,i,t-c[i]);
                temp.pop_back();
            }
        }
        // fun(ans,temp,c,0,t);
        return ans;
    }
};