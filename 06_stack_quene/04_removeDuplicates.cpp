#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

// 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 s 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

// 示例：

// 输入："abbaca"
// 输出："ca"
// 解释：
// 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

// 提示：

// 1 <= s.length <= 105
// s 仅由小写英文字母组成。

class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> stack_s;
        vector<char> v_s = {'m', 'u'};
        for(auto char_s : s){
            if(stack_s.empty())
                stack_s.push(char_s);
            else if(stack_s.top() == char_s)
                stack_s.pop();
            else
                stack_s.push(char_s);
        }
        s.clear();
        while(!stack_s.empty()){
            s.push_back(stack_s.top());
            stack_s.pop();
        }
        // 反转字符串
        for(int slow = 0, fast =s.length() - 1; slow < fast; slow++, fast--){
            swap(s[slow], s[fast]);
        }
        return s;
    }
};

int main(){

    Solution s;

    return 0;
}