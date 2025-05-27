#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            // 将s1的全部元素转移到s2中
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if(s2.empty()){
            // 将s1的全部元素转移到s2中
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        int top = s2.top();
        return top;
    }
    
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

int main() {

    return 0;
}