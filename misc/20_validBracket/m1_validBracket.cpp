#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> stack;
    std::unordered_map<char, char> matching_bracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    // 遍历字符串中元素
    for (char& ch : s) {
        // 若为左括号，则进栈
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } 
        // 若为右括号，判断该元素与栈顶元素是否配对
        else if (ch == ')' || ch == '}' || ch == ']') {
            // 栈为空或者元素与栈顶元素无法配对，则该字符串括号无效
            if (stack.empty() || stack.top() != matching_bracket[ch]) {
                return false;
            }
            // 栈顶匹配成功，则出栈
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string s = "{[()]}";
    if (isValid(s)) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }
    return 0;
}
