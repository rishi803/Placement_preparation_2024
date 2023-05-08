class ATM {
public:    
    map<int,long long,greater<int>>banker;
    ATM() { 
    }
    void deposit(vector<int> banknotesCount) {
        banker[20]+=banknotesCount[0];
        banker[50]+=banknotesCount[1];
        banker[100]+=banknotesCount[2];
        banker[200]+=banknotesCount[3];
        banker[500]+=banknotesCount[4];
    }
    
    vector<int> withdraw(int amount) {
        
        vector<int>ans(5);
        map<int,long long,greater<int>>temp=banker;
        int note=4;
        
        for(auto i=banker.begin();i!=banker.end();i++){
            // cout<<amount<<" "<<i->first<<endl;
            //  for(auto i:banker) cout<<i.second<<" ";
            // cout<<endl;
            if(amount<0){
                banker=temp;
                return {-1};
            }
            
            if(amount==0){
                return ans;
            }
            
            int note_used=0;
            
            
            if(amount>=i->first){
                int curr_notefreq=amount/i->first;
                
                if(curr_notefreq>i->second){
                     note_used+=i->second;
                     amount-=(i->first*i->second);
                     i->second=0;
                }
                else{
                   note_used+=curr_notefreq;
                    amount-=(i->first*curr_notefreq);
                    i->second-=curr_notefreq;
                }
            }
                // else{
                //     note_used++;
                //     amount-=(i->first);
                //     i->second--;
                // }
            ans[note]=note_used;
            note--;
            }
        
        if(amount==0) return ans;
       
        if(amount!=0){
            banker=temp;
            return {-1};
        }
        
        return {-1};
    }
};

