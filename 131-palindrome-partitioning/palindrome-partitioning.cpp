class Solution {
    bool isPali(string temp){
        int i=0,j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void fun(vector<vector<string>>&ans,string temp,string &s, vector<string> arr, int index){
        if(index>=s.size()){
            if(temp.empty()){
                ans.push_back(arr);
            }
            return;
        }
        temp=temp+s[index];
        //ntake
        fun(ans,temp,s,arr,index+1);

        bool ch=isPali(temp);
        if(ch){
            arr.push_back(temp);
            fun(ans,"",s,arr,index+1);
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>arr;
        fun(ans,"",s,arr,0);
        return ans;
    }
};