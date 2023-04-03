class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int i=0,j=people.size()-1,cnt=0;
        
        while(i<=j){
            
            if(people[j]==limit) j--,cnt++;
            else if(people[i]+people[j]>limit) cnt++,j--;
            else {
                cnt++;
                i++;
                j--;
            }
        }
        return cnt;
    }
};