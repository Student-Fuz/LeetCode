#include <iostream>
#include <algorithm> // 包含 std::remove_if
#include <string>

bool isBracket(char ch) {
    return ch == '(' || ch == ')';
}

std::string removeBrackets(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), isBracket), str.end());
    return str;
}

int main() {
    std::string s = "{[()]}";
    std::string removed = removeBrackets(s);
    std::cout << "Original string: " << s << std::endl;
    std::cout << "String after removing brackets: " << removed << std::endl;
    return 0;
}
