class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int temp;
    
    KthLargest(int k, vector<int>& nums) {
        temp=k;
      for(auto i:nums){
          pq.push(i);
          if(pq.size()>k) pq.pop();
      }
    }
    
    int add(int val) {
        pq.push(val);
      if(pq.size()>temp)  pq.pop();
        return pq.top();
    }
};

