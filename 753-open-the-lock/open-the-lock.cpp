class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_map<string,int>m;
        for(int i=0;i<d.size();i++){
            m[d[i]]++;
        }
        
        queue<string>q;
        q.push("0000");
        int ans=0;

        while(q.size()){
            int s=q.size();

            while(s>0){
                string temp=q.front();
                q.pop();
                s--;

                if(m.find(temp)!=m.end()){
                    continue;
                }
                else if(temp==target){
                    return ans;
                }

                m[temp]++;

                for(int i=0;i<4;i++){
                    char ch=temp[i];
                    int val=temp[i]-'0';
                    int dec=val-1;
                    int inc=val+1;
                    if(inc==10) inc=0;
                    if(dec==-1) dec=9;
                    temp[i]='0'+inc;
                    q.push(temp);
                    temp[i]='0'+dec;
                    q.push(temp);
                    temp[i]=ch;
                }
            }
            ans++;
        }
        return -1;
    }
};