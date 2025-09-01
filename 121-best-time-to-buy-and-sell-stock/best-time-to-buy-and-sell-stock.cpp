class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int index=0,n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<=prices[index]){
                index=i;
            }
            maxProfit=max(maxProfit,prices[i]-prices[index]);
        }
        return maxProfit;
    }
};