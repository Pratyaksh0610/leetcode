class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m1=prices[0];
        int m2=prices[1];
        for(int i=2;i<prices.size();i++){
            if(m1>prices[i]){
                m2=min(m2,m1);
                m1=prices[i];
            }
            else if(m2>prices[i]){
                m1=min(m1,m2);
                m2=prices[i];
            }
        }
        int tot=m1+m2;
        if(tot>money){
            return money;
        }
        return money-tot;
    }
};