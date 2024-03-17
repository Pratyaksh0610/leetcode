class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int st=newInterval[0];
        int end=newInterval[1];
        vector<vector<int>>ans;
        // if(intervals[0][0]>end){
        //     ans.push_back(newInterval);
        //     for(int i=0;i<intervals.size();i++){
        //         ans.push_back(intervals[i]);
        //     }
        //     return ans;
        // }
        // else if(intervals[n-1][1]<st){
        //     for(int i=0;i<intervals.size();i++){
        //         ans.push_back(intervals[i]);
        //     }
        //     ans.push_back(newInterval);
        //     return ans;
        // }
        // Now the range is in mid//
        // bool change=true;
        int i=0;
        for(;i<n;i++){
            if(intervals[i][1]<st){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>end){
                break;
                // ans.push_back(intervals[i]);
            }
            else{
                st=min(intervals[i][0],st);
                end=max(intervals[i][1],end);
            }
        }
        vector<int>h;
        h.push_back(st);
        h.push_back(end);
        ans.push_back(h);
        for(;i<n;i++){
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};