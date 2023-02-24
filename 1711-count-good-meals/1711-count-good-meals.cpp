class Solution {
public:
   int countPairs(vector<int>& arr) {
        unordered_map<int,int> freq;
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            for(int pow2=1;pow2<=(1<<21);pow2*=2){
                if(freq.count(pow2-arr[i])) ans+=freq[pow2-arr[i]];
            }
            freq[arr[i]]+=1;
        }
        return ans % (int)(1e9 + 7);
    }

};