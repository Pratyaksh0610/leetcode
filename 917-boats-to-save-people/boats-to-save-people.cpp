class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0,j=n-1;
        int ans=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if(people[j]>limit||people[j]+people[i]>limit){
                ans++;
                j--;
            }
            else if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};