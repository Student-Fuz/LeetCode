#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 

// 示例 1：

// 输入：s = ["h","e","l","l","o"]
// 输出：["o","l","l","e","h"]
// 示例 2：

// 输入：s = ["H","a","n","n","a","h"]
// 输出：["h","a","n","n","a","H"]
 

// 提示：

// 1 <= s.length <= 105
// s[i] 都是 ASCII 码表中的可打印字符


class Solution {
public:
    void reverseString(vector<char>& s) {
        char char_tmp;

        int s_size = s.size();
        for(int i = 0; i < s_size/2; i++){
            char_tmp = s[i];
            s[i] = s[s_size -1 - i];
            s[s_size -1 - i] = char_tmp;
        }
    }
};


int main(){
    Solution s;
    
    return 0;
}