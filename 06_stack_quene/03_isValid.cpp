#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。


class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack_s;
        std:unordered_map<char, char> valid_map = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };
        for(auto char_s : s){
            if(char_s == '(' | char_s == '[' | char_s == '{')
                stack_s.push(char_s);
            else if(stack_s.empty())
                return false;
            else if(valid_map[stack_s.top()] == char_s)
                stack_s.pop();
            else 
                return false;
        }
        if(stack_s.empty())
            return true;
       else
            return false;
    }
};

int main(){

    Solution s;

    return 0;
}