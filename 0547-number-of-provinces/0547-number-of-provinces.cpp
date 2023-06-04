class Solution {
public:
    
    vector<int> parent;
    
    //Find the leader of any group in which x lies
    //if not lie in any group then it is self leader
    int findparent(int x)
    {
        //self leader
        if(parent[x]==-1) return x; 
        //find the leader of self parent
        return parent[x]=findparent(parent[x]);
    }
    
    //Adding 2 friends in a group
    void _union(int a,int b, int &ans)
    {
        //find the leader of both a and b
        int absroot_a=findparent(a),absroot_b=findparent(b);
        
        //if already in same group, i.e leader of both of them are same then return
        if(absroot_a==absroot_b) return; 
       ans--;
        parent[absroot_a]=absroot_b; //v[p_a] will store the index of leader of whole group
    }
    
    int findCircleNum(vector<vector<int>>& M) { 
       
        int n=M.size();
         int ans=n;
         parent.resize(n,-1);  //there will be maximum n group, mark all as a leader
        
        //making group
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)  //if i is friend of j, add them in a group
                { 
                    // cout<<i<<" "<<j<<endl;
                    //if i is in any group then add j in that group
                    //or vice-versa
                    _union(i,j,ans);  //Add them in a group
                    
                }
            }
        }
       return ans;
    }
};