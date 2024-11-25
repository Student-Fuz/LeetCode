#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>

using namespace std;

// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false
// 说明：

// 你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。


class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(queue_A.empty())
            queue_B.push(x);
        else 
            queue_A.push(x);
    }
    
    int pop() {
        if(queue_A.empty()){
            int element = 0;
            while(1){
                element = queue_B.front();
                queue_B.pop();
                if(!queue_B.empty())
                    queue_A.push(element);
                else
                    break;
            }
            return element;
        } 
        else{
            int element = 0;
            while(1){
                element = queue_A.front();
                queue_A.pop();
                if(!queue_A.empty())
                    queue_B.push(element);
                else
                    break;
            }
            return element;
        } 
    }
    
    int top() {
        if(queue_A.empty()){
            int element = 0;
            while(!queue_B.empty()){
                element = queue_B.front();
                queue_B.pop();
                queue_A.push(element);
            }
            return element;
        } 
        else{
            int element = 0;
            while(!queue_A.empty()){
                element = queue_A.front();
                queue_A.pop();
                queue_B.push(element);
            }
            return element;
        } 
    }
    
    bool empty() {
        return (queue_A.empty() && queue_B.empty());
    }

private:
    std::queue<int> queue_A;
    std::queue<int> queue_B;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){


    return 0;
}