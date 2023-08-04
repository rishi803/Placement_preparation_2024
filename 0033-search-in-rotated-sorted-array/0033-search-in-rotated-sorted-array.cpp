class Solution {
public:
    int search(vector<int>& a, int target) {
        
        int low= 0, high= a.size()-1;
        
        while(low <= high){
            
            int mid= low + (high - low)/2;
            
            if(a[mid] == target) return mid;
            
            if(a[low] <= a[mid]){                  // left part is sorted
                
                if(target >= a[low] and target < a[mid]){ // means target lies in this sorted part
                    high= mid-1;
                }
                
                else{          // target may lies in unsorted right part
                    low= mid+1;
                }
            }
            
           else{                                  // else right part is sorted
               
                if(target > a[mid] and target <= a[high]){ // means target lies in this sorted part
                    low= mid+1;
                }
                
                else{          // target may lies in unsorted left part
                    high= mid-1;
                }
           }
        }
        
        return -1;
    }
};