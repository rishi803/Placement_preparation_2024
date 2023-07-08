// arr= [a,b,c,d,e,f,g,h,i,j] and k=4
// if do partition like this:
// a | b c d | e f g | h i j
// sum= a+ b+d + e+g + h+j
// sum = a+ (a+b) + (d+e) + (g+h) + j;


class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        
        if(k==1 or weights.size()==k) return 0;
        
        vector<long>partitionsum;
        for(int i=0;i<weights.size()-1;i++){
            partitionsum.push_back(weights[i]+weights[i+1]);
        }
        
        sort(partitionsum.begin(),partitionsum.end());
        
        long long ans=0;
        int j=partitionsum.size()-1;
        
        for(int i=0;i<k-1;i++){
            ans+=partitionsum[j--];
            ans-=partitionsum[i];
        }
        
        return ans;
    }
};