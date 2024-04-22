class Solution {
public:
    int openLock(vector<string>& d, string target) {
        set<string>s;
        for(int i=0;i<d.size();i++){
            // m[d[i]]++;
            s.insert(d[i]);
        }
        
        queue<string>q;
        q.push("0000");
        int ans=0;

        while(q.size()){
            int ss=q.size();

            while(ss>0){
                string temp=q.front();
                q.pop();
                ss--;

                if(s.find(temp)!=s.end()){
                    continue;
                }
                else if(temp==target){
                    return ans;
                }

                s.insert(temp);
                // m[temp]++;
                string orig=temp;

                for(int i=0;i<4;i++){
                    int val=temp[i]-'0';
                    int dec=val-1;
                    int inc=val+1;
                    if(inc==10) inc=0;
                    if(dec==-1) dec=9;
                    temp[i]='0'+inc;
                    q.push(temp);
                    temp[i]='0'+dec;
                    q.push(temp);
                    temp[i]=orig[i];
                }
            }
            ans++;
        }
        return -1;
    }
};