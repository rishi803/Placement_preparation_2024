class Solution {
public:
    bool isValid(string s1)
{

   if(s1.size()>3||s1.size()==0) return false;
   
   if(s1.size()>1 && s1[0]=='0') return false;
   
   if(s1.size() && stoi(s1)>255) return false;
   
   else
   return true;
}

void recur(int idx, int dots, string temp, vector<string>& ans, string s)
{
	// we have to place 3 dots in the string to make 4 partitions
	
    if(dots==3)
    {
       // pushing last partition after checking its validity
			
        if(isValid(s.substr(idx)))
        {
       
            ans.push_back(temp+s.substr(idx));
            
        }
        return;
    }


    for(int j=idx; j<s.size() ;j++)
    {

	if( isValid(s.substr(idx, j-idx+1)))
	{
        // cout<<s.substr(idx, j-idx+1)<<" "<<s.substr(j+1)<<endl;
        
        
		temp.push_back(s[j]);
		temp.push_back('.');

		recur(j+1, dots+1, temp, ans, s);

	   
		temp.pop_back();


        }
    }
    
    return;
    
}

vector<string> restoreIpAddresses(string s) {
    
    vector<string> ans;
    
    if(s.size()<4) return ans;
    
    recur(0, 0, "", ans, s);
    
    return ans;
}
};

