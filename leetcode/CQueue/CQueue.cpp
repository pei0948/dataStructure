class CQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        int valDel;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                valDel=stack1.top();
                stack1.pop();
                stack2.push(valDel);
            }
        }
        if(stack2.empty())
        {
            return -1;
        }
        else
        {
            valDel=stack2.top();
            stack2.pop();
            return valDel;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */