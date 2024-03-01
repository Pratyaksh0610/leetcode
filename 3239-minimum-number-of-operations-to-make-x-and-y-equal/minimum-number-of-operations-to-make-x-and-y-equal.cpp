#define pi pair<int,int>
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pi>q;
        q.push({x,0});
        int ans=INT_MAX;
        if(y>x){
            return abs(y-x);
        }
        while(q.size()){
            int s=q.size();
            while(s>0){
                s--;
                pi temp=q.front();
                int val=temp.first,cnt=temp.second;
                q.pop();
                if(val<y){
                    ans=min(ans,cnt+(abs(val-y)));
                    continue;
                }
                else if(val==y){
                    ans=min(ans,cnt);
                }
                else{
                    ans=min(ans,cnt+(abs(val-y)));
                    int d1=val/11,d5=val/5;
                    int v11=abs(d1*11 -val),v12=abs((d1+1)*11-val);
                    if(v11>v12){
                        q.push({(val+v12)/11,cnt+v12+1});
                    }
                    else{
                        q.push({(val-v11)/11,cnt+v11+1});
                    }
                    v11=abs(d5*5 -val),v12=abs((d5+1)*5-val);
                    if(v11>v12){
                        q.push({(val+v12)/5,cnt+v12+1});
                    }
                    else{
                        q.push({(val-v11)/5,cnt+v11+1});
                    }
                }
            }
        }
        return ans;
    }
};