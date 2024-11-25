#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

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


class MyQueue {
public:

    MyQueue() {


    }
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() {
        if(stack_out.empty()){
            while(!stack_in.empty()){
                // stack_in ===> stack_out
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int pop_element = stack_out.top();
        stack_out.pop();
        return pop_element;
    }
    
    int peek() {
        if(stack_out.empty()){
            // stack_in ===> stack_out
            while(!stack_in.empty()){
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }
    
    bool empty() {
        if(stack_out.empty() && stack_in.empty())
            return true;
        else
            return false;
    }

private:
        std::stack<int> stack_in;
        std::stack<int> stack_out;
};
int main(){


    return 0;
}