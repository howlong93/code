class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> ele;
    map<int, int> save;
    MinStack() {
        while (!ele.empty()) ele.pop();
        save.clear();
    }

    void push(int val) {
        ele.push(val);
        save[val]++;
    }

    void pop() {
        int k = ele.top();
        ele.pop();
        save[k]--;
        if (save[k] == 0) save.erase(k);
    }

    int top() {
        return ele.top();
    }

    int getMin() {
        return save.begin()->first;
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
