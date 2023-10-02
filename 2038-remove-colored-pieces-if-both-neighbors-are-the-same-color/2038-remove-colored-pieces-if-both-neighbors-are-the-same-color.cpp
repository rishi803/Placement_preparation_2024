class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int alice=0, bob=0;
        
        for(int i=1; i<colors.size()-1; i++){
            if(colors[i-1] == colors[i] and colors[i] == colors[i+1]){
                
                if(colors[i] == 'A') alice++;    // count continuous 'A' ('AAA' -> 1 , 'AAAA' -> 2)
                else bob++;  // count continuors 'B' ('BBB'-> 1, 'BBBB' -> 2, 'BBBBB' -> 3...)
            }
        }
        
        return alice > bob;
    }
};