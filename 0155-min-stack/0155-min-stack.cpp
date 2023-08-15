class MinStack {
public:
    vector<pair<int,int>> arr;
    MinStack() {
    }
    
    void push(int val) {
        if(arr.empty()){
            arr.push_back({val,val});
            return;
        }
        int min = (val >= arr[arr.size() - 1].second) ? arr[arr.size() - 1].second : val;

        arr.push_back({val,min});
        return;
    }
    
    void pop() {
        if(arr.empty()){
            return;
        }
        arr.pop_back();
    }
    
    int top() {
        if(arr.empty()){
            return -1;
        }
        return arr[arr.size() - 1].first;
    }
    
    int getMin() {
        if(arr.empty()){
            return -1;
        }
        return arr[arr.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */