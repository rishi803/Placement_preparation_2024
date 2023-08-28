class MyStack {
public:
    
    queue<int> que;
	
	 void push(int x) {
         int sz= que.size();
         
		que.push(x);
         
		while(sz--){
			que.push(que.front());   // last element reside at front
			que.pop();
		}
	}

	
	int pop() {
        
        int ans= que.front();
		que.pop();
        return ans;
	}

	
	int top() {
		return que.front();
	}

	
	bool empty() {
		return que.empty();
	}
};
