class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
//         priority_queue<int,vector<int>,greater<int>>pq;      // USING PRIORITY QUEUE
//         for(int i=0;i<capacity.size();i++){
//             pq.push((capacity[i]-rocks[i]));
//         }
//         int ans=0;
        
//         while(!pq.empty()){
//             int f=pq.top();
//             pq.pop();
           
//             if(f>0 and additionalRocks-f>=0){
//                additionalRocks-=f;
//                 f=0;
                
//             }
//             if(f==0) ans++;
//         }
//         return ans;
        
//          int cnt=0;                                     // USING MAP
//         map<int,int>ans;
//         for(int i=0;i<rocks.size();i++){
//             if(capacity[i]-rocks[i]>0){
//                 ans[capacity[i]-rocks[i]]++;
//             }
//             else if (capacity[i]-rocks[i]==0) cnt++;
//         }
//         for(auto it:ans){
            
//           while(additionalRocks-it.first>=0 and it.second--){
//             additionalRocks= additionalRocks-it.first;
//               cnt++;
//           }
//         }
//         return cnt;
        
         for(int i=0;i<capacity.size();i++)        // USING SORTING WITHOUT TAKING ANY EXTRA SPACE 
             
        capacity[i]-=rocks[i];  //Subtacting so that this array will now indicate how many more rocks we can place at a given idx,like ax permissible rocks
        sort(capacity.begin(),capacity.end());   //Sorting it as the ones with least capacity should be filled first of the availabe rocks so as to make max bags full
        int cnt=0; //To store the count of the full bags
        for(int rock:capacity)
        {
            if(rock==0)
            cnt++;  //Means the bag is full
            else if(rock<=additionalRocks)
            {
                additionalRocks-=rock;  //As we are taking the rocks into the bag we have to reduce it from the additionalRocks 
                cnt++;
                rock=0;
            }
            else  //When we are not able to fill the bag completely like additionalRocks is < than required rock
            break;
        }
        return cnt;
        
    }
};