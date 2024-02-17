class Solution {
public:
    int minNumberOfFrogs(string s) {
        // vector<int>c,r,o,a,k;
        int maxi=0,curr=0;
        unordered_map<char,vector<int>>m;
        for(int i=0;i<s.size();i++){
            if(s[i]=='c'){
                curr++;
            }
            else if(s[i]=='k'){
                curr--;
            }
            maxi=max(maxi,curr);
            m[s[i]].push_back(i);
        }
        int ss=m['c'].size();
        if(ss!=m['r'].size()||ss!=m['o'].size()||ss!=m['a'].size()||ss!=m['k'].size()){
            return -1;
        }
        for(int i=0;i<ss;i++){
            if(m['c'][i]>=m['r'][i]||m['r'][i]>=m['o'][i]||m['o'][i]>=m['a'][i]||m['a'][i]>=m['k'][i]){
                return -1;
            }
        }
        return maxi;
    }
};