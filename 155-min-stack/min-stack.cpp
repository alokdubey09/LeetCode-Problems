class MinStack {
private:
    stack <pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        
        // Update the current minimum 
        int mini = min(getMin(), value);
        
        // Add the pair to the stack
        st.push({value, mini});
    }
    
    void pop() {
        st.pop(); 
    }
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */