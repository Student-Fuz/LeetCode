#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

// 请你计算该表达式。返回一个表示表达式值的整数。

// 注意：

// 有效的算符为 '+'、'-'、'*' 和 '/' 。
// 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
// 两个整数之间的除法总是 向零截断 。
// 表达式中不含除零运算。
// 输入是一个根据逆波兰表示法表示的算术表达式。
// 答案及所有中间计算结果可以用 32 位 整数表示。


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> my_stack;
        unordered_set<string> operator_set({"+" , "-" , "*" , "/"});

        for(auto token : tokens){
            if(operator_set.find(token) == operator_set.end())
                my_stack.push(token);
            else{
                int operand_1 = std::stoi(my_stack.top());
                my_stack.pop();
                int operand_2 = std::stoi(my_stack.top());
                my_stack.pop();

                int result = 0;
                if(token == "+")
                    result = operand_2 + operand_1;
                else if(token == "-")
                    result = operand_2 - operand_1;
                else if(token == "*")
                    result = operand_2 * operand_1;
                else    
                    result = operand_2 / operand_1;

                my_stack.push(std::to_string(result));
            }
        }

        return std::stoi(my_stack.top());
    }
};

int main(){

    Solution s;

    return 0;
}