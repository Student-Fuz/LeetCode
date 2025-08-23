#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> x_stack;
    stack<int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        minStack.push(min(val, minStack.top()));
        x_stack.push(val);
    }
    
    void pop() {
        minStack.pop();
        x_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
    


int main() {

    cout << "Hello World" << endl;

    return 0;
}