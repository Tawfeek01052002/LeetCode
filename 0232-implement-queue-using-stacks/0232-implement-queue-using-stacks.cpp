class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    // O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // O(n)
    int pop() {
        int x=-1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()){
            x=s2.top();
            s2.pop();
        }
        return x;
    }
    
    // O(n)
    int peek() {
        int x=-1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()){
            x=s2.top();
        }
        return x;
    }
    
    // O(1)
    bool empty() {
        return s1.empty() && s2.empty();
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