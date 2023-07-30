class Solution {
public:
    string minWindow(string s, string t) {
        int head=0,tail=0,minlen=INT_MAX,start_pos=0,sz=0;
        int map[128]={};
        
        for(auto it:t){
            map[it]++;
        }
        
        for(head=0;head<s.size();head++){
            map[s[head]]--;           // operation
            
            if(map[s[head]]>=0) sz++;
            
            while(sz==t.size()){
                if(minlen > (head-tail+1)){
                    minlen= head-tail+1;
                    start_pos= tail;
                }
                map[s[tail]]++;
                
                if(map[s[tail]]>0) sz--;
                tail++;
            }
        }
        
        return minlen==INT_MAX?"": s.substr(start_pos,minlen);
    }
};