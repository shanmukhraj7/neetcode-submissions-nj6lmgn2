class MinStack {
public:
    stack<int> st1, st2;

    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty()) st2.push(val);
        else st2.push(min(st2.top(), val));
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
