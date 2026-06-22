class MinStack {
private:
    // implementation of stack via vector
    vector<pair<int, int>> stack;
    
public:
    // constructor for memory allocation
    MinStack() {
    }
    
    // push() adds element to top of stack 
    void push(int val) {
        // return val as both top and min element if stack is empty
        if (stack.empty()) {
            stack.push_back({val, val});
        } 
        // else compare val with existing values and update minVal
        else {
            int minVal = std::min(val, stack.back().second);

            // push top and minVal
            stack.push_back({val, minVal});
        }
    }
    
    // pop() removes topmost element of stack, works only if stack has atlest one val
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }
    
    // top() returns topmost val which is store as first element in vector created
    int top() {
        return stack.back().first;
    }
    
    // getMin() returns minVal which is stored as second element in vector created
    int getMin() {
        return stack.back().second;
    }
};
