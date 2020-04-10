class MinStack {
   public:
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> values;
    priority_queue<int, vector<int>, greater<int>> remove;
    MinStack() {
        stack<int> s;
        priority_queue<int> remove;
        priority_queue<int> values;
    }

    void push(int x) {
        s.push(x);
        values.push(x);
    }

    void pop() {
        if (s.size()) {
            remove.push(s.top());
            while (remove.size() && values.size()) {
                if (remove.top() != values.top()) break;
                remove.pop();
                values.pop();
            }
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return values.top();
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