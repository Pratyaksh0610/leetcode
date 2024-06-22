#define ll long long int

class Solution {
    int finalValue(int mul, ll number) {
        if(mul==0){
            mul=1;
        }
        ll val = mul * number;
        if (val < INT_MIN) {
            return INT_MIN;
        } else if (val > INT_MAX) {
            return INT_MAX;
        }
        return val;
    }
    bool isNumber(char ch) {
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' ||
            ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
            return true;
        }
        return false;
    }

public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n){
            return 0;
        }
        int mul = 0;
        ll number = 0;
        bool started=false;
        while (i < n) {
            if (((mul != 0||started) && (s[i] == '+' || s[i] == '-'))) {
                return finalValue(mul, number);
            } else if (s[i] == '+') {
                mul = 1;
            } else if (s[i] == '-') {
                mul = -1;
            } else if (isNumber(s[i])) {
                number*=10;
                number+=(s[i]-'0');
                started=true;
                if(number>INT_MAX){
                    return finalValue(mul,number);
                }
            }
            else{
                return finalValue(mul,number);
            }
            i++;
        }
        return finalValue(mul,number);
    }
};