#define ll long long int
class p{
    public:
    int roomNum;
    ll duration;
    p(int a,ll b){
        roomNum=a,
        duration=b;
    }
};
class compa{
    public:
    bool operator ()(p &a,p &b){
        if(a.duration<b.duration){
            return false;
        }
        else if(a.duration>b.duration){
            return true;
        }
        else{
            if(a.roomNum<b.roomNum){
                return false;
            }
            return true;
        }
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        //meeting will happen in lowest unused number
        //no rooms free,delayed then
        //room is unused
        priority_queue<p,vector<p>,compa>pq;
        priority_queue<int,vector<int>,greater<int>>rq;
        unordered_map<int,ll>s;
        sort(m.begin(),m.end());
        pq.push(p(0,m[0][1]));
        int i=1;
        s[0]++;
        int cnt=1;
        while(cnt<n){
            rq.push(cnt++);
        }
        while(i<m.size()){
            ll fastest=pq.top().duration;
            int rm=pq.top().roomNum;
            if(fastest>m[i][0]){
                if(pq.size()==n){
                    pq.pop();
                    ll val=fastest-(ll)m[i][0]+(ll)m[i][1];
                    pq.push(p(rm,val));
                    // cout<<rm<<" "<<val<<endl;
                    s[rm]++;
                }
                else if(pq.size()<n){
                    int r=rq.top();
                    rq.pop();
                    pq.push(p(r,m[i][1]));
                    // cout<<cnt<<" "<<m[i][1]<<endl;
                    s[r]++;
                    // cnt++;
                }
                else if(pq.size()>n){
                    // cout<<"SIZE bdh gaya"<<endl;
                }
            }
            else if(fastest<=m[i][0]){
                while(pq.size()&&pq.top().duration<=m[i][0]){
                    rq.push(pq.top().roomNum);
                    pq.pop();
                }
                // pq.pop();
                rm=rq.top();
                rq.pop();
                pq.push(p(rm,m[i][1]));
                // cout<<rm<<" "<<m[i][1]<<endl;
                s[rm]++;
            }
            i++;
        }
        ll mini=LLONG_MIN;
        int ele=INT_MAX;
        for(auto it:s){
            ll freq=it.second;
            if(freq>mini){
                mini=freq;
                ele=it.first;
            }
            else if(freq==mini){
                ele=min(it.first,ele);
            }
        }
        return ele;
    }
};