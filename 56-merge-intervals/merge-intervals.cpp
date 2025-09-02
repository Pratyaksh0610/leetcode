class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int index=0,n=intervals.size();
        while(index<n){
            int st=intervals[index][0],end=intervals[index][1];
            while(index<n&&intervals[index][0]<=end){
                end=max(end,intervals[index++][1]);
            }
            vector<int>temp={st,end};
            ans.push_back(temp);
        }
        return ans;
    }
};