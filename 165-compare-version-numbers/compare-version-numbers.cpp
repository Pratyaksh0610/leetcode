class Solution {
public:
    int compareVersion(string s, string s2) {
        int n1=s.size(),n2=s2.size();
        int i=0,j=0;
        int num1=0,num2=0;

        while(i<n1&&j<n2){
            while(i<n1&&s[i]!='.'){
                int dig1=s[i]-'0';
                    num1*=10;
                    num1+=dig1;
                i++;
            }
            while(j<n2&&s2[j]!='.'){
                int dig2=s2[j]-'0';
                    num2*=10;
                    num2+=dig2;
                j++;
            }
            if(num1>num2)return 1;
            if(num2>num1)return -1;
            num1=0;
            num2=0;
            i++;
            j++;
        }
        while(i<n1){
            while(i<n1&&s[i]!='.'){
                    int dig1=s[i]-'0';
                        num1*=10;
                        num1+=dig1;
                    i++;
            }
            if(num1>num2)return 1;
            if(num2>num1)return -1;
            i++;
        }
        while(j<n2){
            while(j<n2&&s2[j]!='.'){
                    int dig2=s2[j]-'0';
                        num2*=10;
                        num2+=dig2;
                    j++;
            }
            if(num1>num2)return 1;
            if(num2>num1)return -1;
            j++;
        }
        return 0;

    }
};