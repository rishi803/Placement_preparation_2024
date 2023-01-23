class Solution {
public:
    string alphabetBoardPath(string target) {
        
        vector<string>alpha={"      "," abcde", " fghij", " klmno", " pqrst", " uvwxy", " z"};
        string ans;
        
        int curr_row=1,curr_col=1;
        
        for(auto &character:target){
            
            int search_row= (ceil)((character-'a'+1)/5.0);
            int search_col=((character-'a')%5)+1;
            
           
            int y=(curr_col-search_col);
            
            if( search_row==6 and y!=0){
                
                ans+=string(abs(curr_row-5),'D');
                curr_row=5;
                ans+=string(curr_col-1,'L');
                curr_col=1;
                y=(curr_col-search_col);
            }
             int x=(curr_row-search_row);
            
        
            if(x<0){
                x*=-1;
                ans+=string(x,'D');
            }
            else{
                ans+=string(x,'U');
            }
            
            if(y<0){
                y*=-1;
                ans+=string(y,'R');
            }
            else{
                ans+=string(y,'L');
            }
            ans+='!';
            
            curr_row=search_row;
            curr_col=search_col;
        }
        return ans;
    }
};