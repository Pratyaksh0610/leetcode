class Solution {
    void fun(string& ans, int k, int fact, set<int>& s) {
        if (k == -1) {
            return;
        } else if (k == 0) {
            while (s.size()) {
                auto it = s.begin();
                int val = *it;
                char ch = '0' + val;
                ans = ans + ch;
                s.erase(*it);
            }
            return;
        }
        int num = k / fact;
        k = k - (num)*fact;
        auto it = s.begin();
        // num= num*fact;
        while (num > 0) {
            it++;
            num--;
        }
        int val = *it;
        char ch = '0' + val;
        ans = ans + ch;
        // ans = ans + ('0' + *it);
        s.erase(*it);
        fun(ans, k, fact / s.size(), s);
    }

public:
    string getPermutation(int n, int k) {
        k--;
        string ans = "";
        int fact = 1;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        for (int i = 1; i < n; i++) {
            fact *= i;
        }
        fun(ans, k, fact, s);
        return ans;
    }
};