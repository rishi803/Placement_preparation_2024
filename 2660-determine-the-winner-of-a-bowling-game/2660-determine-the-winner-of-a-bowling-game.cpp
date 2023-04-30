class Solution {
public:
//     player1 = [3,5,7,6], player2 = [8,10,10,2]
// Output: 2
// Explanation: The score of player1 is 3 + 5 + 7 + 6 = 21.
// The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
// Score of player2 is more than the score of player1, so, player2 is the winner, and the answer is 2..
    
//     1 if the score of player 1 is more than the score of player 2,
// 2 if the score of player 2 is more than the score of player 1, and
// 0 in case of a draw.
 
    int isWinner(vector<int>& player1, vector<int>& player2) {
    int o=0,t=0;
    
        for(int i=0;i<player1.size();i++){
            
            if(i>=1 and player1[i-1]>=10) o+=2*player1[i];
            else if(i>=2 and (player1[i-1]>=10 or player1[i-2]>=10)) o+=2*player1[i];
            else o+=player1[i];
        }
    // cout<<o<<" ";
    
     for(int i=0;i<player2.size();i++){
            
         if(i>=1 and player2[i-1]>=10) t+=2*player2[i];
           else if(i>=2 and (player2[i-1]>=10 or player2[i-2]>=10)) t+=2*player2[i];
            else t+=player2[i];
        }
        // cout<<t<<endl;
    if(o>t) return 1;
    else if(t>o) return 2;
    else return 0;
    }
};