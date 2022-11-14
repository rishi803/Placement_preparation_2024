class Solution {
public:
    bool help(vector<vector<char>>&board,string &word,int i,int j,int idx){
        
        if(idx==word.size()) return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[i].size() or board[i][j]!=word[idx]) return false;
        
        board[i][j] = '0';        // mark as visited
        
        bool ans= help(board,word,i,j+1,idx+1) or
                 help(board,word,i+1,j,idx+1) or
                 help(board,word,i-1,j,idx+1) or
                 help(board,word,i,j-1,idx+1);
        
     board[i][j] = word[idx];  // backtrack for other search
     return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
				//check if the characters are equal then call DFS
                if(board[i][j] == word[0])
                  if( help(board, word, i, j, 0))
                    return true;
        
        return false; 
    }
};