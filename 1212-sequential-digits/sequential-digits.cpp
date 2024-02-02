#define ll long long int
class Solution {
public:
    vector<int> sequentialDigits(ll low, ll high) {
        vector<int>ans;
        string s="123456789";
        for(int i=2;i<=9;i++){
            for(int j=0;j<s.size()-i+1;j++){
                string temp=s.substr(j,i);
                ll num=stoi(temp);
                if(num>high){
                    break;
                }
                else if(num<low){
                    continue;
                }
                ans.push_back(stoi(temp));
            }
        }
        return ans;
    }
};