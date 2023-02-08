class Solution {
public:
    bool canReach(vector<int>& arr, int start_index) {
        
        queue<int>q;
        q.push(start_index);
        
        
        
        while(!q.empty()){
            
            int valid_index=q.front();
            q.pop();
            
            
            int stored=arr[valid_index];
            
            arr[valid_index]*=-1;             // make this element visited
            
            // cout<<valid_index<<endl;
            
            if(arr[valid_index]==0){
                return true;
            }
            if(valid_index + stored >=0 and valid_index + stored < arr.size() and arr[valid_index + stored] >= 0){
                q.push(valid_index + stored);
            }
             if(valid_index - stored >=0  and valid_index - stored < arr.size() and arr[valid_index - stored]>= 0){
                q.push(valid_index - stored);
            }
            
            
        }
        
        return false;
    }
};