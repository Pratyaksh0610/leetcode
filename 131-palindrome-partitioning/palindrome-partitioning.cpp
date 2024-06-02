class Solution {
private:
    bool isPalindrome(string& s) {
        if (s.size() == 0)
            return false;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    void fun(vector<vector<string>>& ans, string& s, int ind, vector<string> temp,
             string tt) {
                if(ind>=s.size()){
                    if(isPalindrome(tt)||tt.size()==0){
                        temp.push_back(tt);
                        ans.push_back(temp);
                    }
                    return;
                }
                bool check=isPalindrome(tt);
                // tt.push_back(s[ind]);
                fun(ans,s,ind+1,temp,tt+s[ind]);
                if(check){
                    temp.push_back(tt);
                    tt=s[ind];
                    fun(ans,s,ind+1,temp,tt);
                }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        vector<vector<string>> ans;
        vector<string> temp;
        fun(ans, s, 0, temp, "");
        return ans;
    }
};