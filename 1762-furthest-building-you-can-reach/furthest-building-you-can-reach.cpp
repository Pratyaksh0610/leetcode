#define ll long long int
class Solution {
public:
    int furthestBuilding(vector<int>& h, ll b, ll l) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll i=1;
        for(;i<h.size();i++){
            // cout<<i<<" "<<pq.size()<<" "<<b<<" "<<h[i]-h[i-1]<<endl;
            if(h[i]-h[i-1]<=0){
                continue;
            }
            if(pq.size()<l){
                pq.push(h[i]-h[i-1]);
            }
            else if(pq.size()==l&&l>0){
                ll ele=pq.top();
                pq.pop();
                ll diff=h[i]-h[i-1];
                ll maxi=max(diff,ele);
                ll mini=min(diff,ele);
                b-=mini;
                pq.push(maxi);
            }
            else if(l==0){
                b-=h[i]-h[i-1];
            }
            if(b<0){
                break;
            }
        }
        return i-1;
    }
};