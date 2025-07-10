#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/implement-stack-using-queues/

class MyStack {
private:
    queue<int> q1;
    queue<int> q2; 
public:
    MyStack() {

    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                int tmp = q2.front();
                q1.push(tmp);
                q2.pop();
            }
        }else{
            q2.push(x);
            while(!q1.empty()){
                int tmp = q1.front();
                q2.push(tmp);
                q1.pop();
            }
        }
    }
    
    int pop() {
        if(q1.empty()){
            int tmp = q2.front();
            q2.pop();
            return tmp;
        }else{
            int tmp = q1.front();
            q1.pop();
            return tmp;
        }
    }
    
    int top() {
        if(q1.empty()){
            return q2.front();
        }else{
            return q1.front();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
    

int main() {

    return 0;
}