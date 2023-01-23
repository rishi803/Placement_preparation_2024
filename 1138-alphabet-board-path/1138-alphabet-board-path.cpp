class Solution {
public:
   //  move UP and LEFT before DOWN and RIGHT to avoid "trapped" in 'z'. Add 'a' to string for initialization.

    string alphabetBoardPath(string target) {
       string res;
        //for letter ?, the row index is (?-'a') / 5, the row index is (?- 'a') % 5.
        int row1 = 0, col1 = 0;
        for(int i = 0; i < target.size(); i++){
            int row2 = (target[i] - 'a') / 5;
            int col2 = (target[i] - 'a') % 5;
            
            if(col2 < col1){  
                 res.append(string(col1 - col2, 'L'));
            }
            if(row2 > row1){                
                 res.append(string(row2 - row1, 'D'));
            }
            if(row2 < row1){  
                 res.append(string (row1 - row2, 'U'));
            }
            if(col2 > col1){   
                 res.append(string (col2 - col1, 'R'));
            }                        
            res.push_back('!');
            row1 = row2;
            col1 = col2;
        }
        return res;
    }
};