class Solution {
    class p{
        private:
        public:
        char key;
        int  val;
        p(){};
        p(char s,int a){
            key=s;
            val=a;
        }
    };
    class compa{
        private:
        public:
        bool operator()(p &t,p &h){
            if(t.val<h.val){
                return true;
            }
            else{
                return false;
            }
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        int l=tasks.size();
        if(n==0){
            return l;
        }
        unordered_map<char,int>m;
        for(int i=0;i<l;i++){
            m[tasks[i]]++;
        }
        priority_queue<p,vector<p>,compa>pq;
        for(auto it:m){
            p t(it.first,it.second);
            pq.push(t);
        }
        int used=0,blank=0;
        p temp=pq.top();
        int termi=temp.val;
        pq.pop();
        blank=(temp.val-1)*n;
        used+=temp.val+blank;

        while(pq.size()){
            if(blank<=0){
                used+=pq.top().val;
                pq.pop();
            }
            else{
                p te=pq.top();
                pq.pop();
                int v=te.val;
                if(v==termi){
                    used++;
                    v--;
                }
                int rem=blank-v;
                if(rem<=0){
                    v-=blank;
                    blank=0;
                    used+=v;
                }
                else{
                    blank-=v;
                }
            }
        }
        return used;
    }
};