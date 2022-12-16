class MyQueue {
public:
   stack<int> helper, nums;

    
    void push(int x) {
     while (!nums.empty()) {
			helper.push(nums.top());
			nums.pop();
		}
		nums.push(x);
		while (!helper.empty()) {
			nums.push(helper.top());
			helper.pop();
		}   
    }
    
    int pop() { int x=nums.top();
          nums.pop();
               return x;
    }
    
    int peek() {
        return nums.top();
    }
    
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */