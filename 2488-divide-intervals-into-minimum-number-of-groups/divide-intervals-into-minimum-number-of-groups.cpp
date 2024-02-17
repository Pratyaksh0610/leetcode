class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0,n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(i<n){
            if(pq.empty()){
                pq.push(intervals[i][1]);
            }
            else{
                int top=pq.top();
                pq.pop();
                if(top<intervals[i][0]){
                    pq.push(intervals[i][1]);
                }
                else{
                    pq.push(top);
                    pq.push(intervals[i][1]);
                }
            }
            i++;
        }
        return pq.size();
    }
};