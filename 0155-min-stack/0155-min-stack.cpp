#include <stack>
#include <limits>
class MinStack {
private:
    std::stack<int> mainStack; 
    std::stack<int> minStack; 
public:
    MinStack() {
        
    }
    void push(int val) {
        mainStack.push(val); 
        
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.empty()) return; 
        int topValue = mainStack.top();
        mainStack.pop(); 
        if (topValue == minStack.top()) {
            minStack.pop();
        }
    }
    
    int top() {
        return mainStack.top(); 
    }
    
    int getMin() {
        return minStack.top(); 
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