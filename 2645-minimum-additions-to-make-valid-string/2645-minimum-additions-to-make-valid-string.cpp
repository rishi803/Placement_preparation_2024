class Solution {
public:
    int addMinimum(string word) {
        
        int result=0;
        
        for(int i=0;i<word.size();){
            
            if(word.substr(i,3)=="abc"){
                i+=3;
            }
            else if(word.substr(i,2)=="ab" or word.substr(i,2)=="bc" or word.substr(i,2)=="ac"){
                i+=2;
                result+=1;
            }
            else{
                i+=1;
                result+=2;
            }
        }
        return result;
    }
};