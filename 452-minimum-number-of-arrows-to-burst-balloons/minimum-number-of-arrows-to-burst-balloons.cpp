class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0,cnt=0,n=points.size();
        while(i<n){
            int st=points[i][0];
            int end=points[i][1];
            cnt++;
            i++;
            while(i<n&&(st<=points[i][0]&&end>=points[i][0])){
                st=max(points[i][0],st);
                end=min(points[i][1],end);
                i++;
            }
        }
        return cnt;
    }
};