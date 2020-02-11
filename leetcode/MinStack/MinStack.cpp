class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> minS;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(minS.empty() || x<=minS.top())
        {
            minS.push(x);
        }
    }
    
    void pop() {
        if(s.empty())
        {
            return;
        }
        if(s.top()==minS.top())
        {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(minS.empty())
        {
            return 0;
        }
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */