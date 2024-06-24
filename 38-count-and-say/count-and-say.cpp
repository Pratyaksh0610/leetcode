class Solution {
    private:
    string fun(int n,string &s){
        if(n==1){
            return s;
        }
        char ch=s[0];
        int freq=1;
        string temp;
        for(int i=1;i<s.size();i++){
            if(s[i]==ch){
                freq++;
            }
            else{
                temp+=to_string(freq)+ch;
                ch=s[i];
                freq=1;
            }
        }
        temp+=to_string(freq)+ch;
        return fun(n-1,temp);
    }
public:
    string countAndSay(int n) {
        string s="1";
        return fun(n,s);
    }
};