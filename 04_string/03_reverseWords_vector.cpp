#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

// 给你一个字符串 s ，请你反转字符串中 单词 的顺序。

// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 

// 示例 1：

// 输入：s = "the sky is blue"
// 输出："blue is sky the"
// 示例 2：

// 输入：s = "  hello world  "
// 输出："world hello"
// 解释：反转后的字符串中不能存在前导空格和尾随空格。
// 示例 3：

// 输入：s = "a good   example"
// 输出："example good a"
// 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。

// 数组操作
// 时间复杂度O(2n)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> str_vec;
        bool prev_space_flag = true;

        string result_str;

        for(auto it = s.begin(); it < s.end(); it++){
            if(*(it) == ' '){
                prev_space_flag = true;
                continue;
            }
            if(prev_space_flag){
                str_vec.push_back(string(1, *(it)));
                prev_space_flag = false;
            }
            else{
                str_vec.back().push_back(*(it));
            }    
        }

        int str_vec_size = str_vec.size();   
        for(int i = str_vec_size-1; i > -1; i--){
            result_str += (str_vec[i] + " ");
        }
        
        if (!result_str.empty()) {
            result_str.pop_back(); // 去掉尾部多余空格
        }
        return result_str;
    }
};

int main(){

    Solution s;
    // cout << s.twoSum();
    return 0;
}