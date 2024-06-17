#define pi pair<int,int>
class StockSpanner {
public:
stack<pi>st;
int cnt=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        cnt++;
        while(st.size()&&st.top().first<=price){
            st.pop();
        }
        int ans=-1;
        if(st.size()){
            ans+=cnt-st.top().second+1;
        }
        else{
            ans=cnt;
        }
        st.push({price,cnt});
return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */