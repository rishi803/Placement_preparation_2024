class Solution {
public:
    string minWindow(string s, string t) {
        
        int head=0,tail=0,minstring_start=0,minlen=INT_MAX;
        int sz_required=0;
        
        int map[128]={};
        for(auto i:t) map[i]++;
        
        for(head=0;head<s.size();head++){
            
            if(map[s[head]]>0) sz_required++;
            map[s[head]]--;
        
            while(sz_required==t.size()){
                
                if(minlen > (head-tail+1)){
                    minlen=head-tail+1;
                    minstring_start=tail;
                }
                  map[s[tail]]++;
            
              if(map[s[tail]]>0) sz_required--;
                tail++;
                
                } 
        }
      
        return minlen==INT_MAX?"":s.substr(minstring_start,minlen);
    }
};