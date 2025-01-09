#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述


// Solution
// 时间复杂度O(1)解法
class Solution {
public:
    string reverseWords(string s) {
        // 倒序整个字符串
        for(int i = 0, j = s.size()-1; i < j; i++, j--)
            swap(s[i], s[j]);
        
        // 单词存在空格了
        int space_flag = true;
        // 字符串结尾索引 str_end 单词开头索引i
        int str_end = 0;
        int i = 0;
        // 删除空格 并 倒序单词
        for(int j = 0; j < s.size(); j++){
            if(s[j] != ' '){
                if(s[str_end++] = s[j]);
                space_flag = false;
            }
            else if(!space_flag){
                space_flag = true;
                s[str_end++] = s[j];
                // 倒序单词
                for(int k = i, l = str_end-2; k < l; k++, l--)
                    swap(s[k], s[l]);
                i = str_end;
            }
        }
        if(s[str_end-1] == ' ')
            s.resize(str_end-1);
        else{ // 最后一个没有空格， 倒序最后一个单词
            for(int k = i, l = str_end-1; k < l; k++, l--)
                swap(s[k], s[l]);
            s.resize(str_end);
        }
        return s;
    }
};


class Solution {
public:
    // 双指针 反转字符串 左闭右开
    void reverse(string& s, int start, int end){
        char char_tmp;
        for(int i = 0; i < end; i++){
            char_tmp = s[i];
            s[i] = s[end-1-i];
            s[end-1-i] = char_tmp;
        }
    }
    // 双指针 删除多余空格 标准答案----比较巧妙
    void removeExtraSpace(string& s){
        int s_size = s.size();
        int slow_index=0;
        for(int fast_index=0; fast_index < s_size; fast_index++){
            if(s[fast_index] != ' '){
                if(slow_index != 0) s[slow_index++] = ' ';
                while(s[fast_index] != ' '){
                    s[slow_index++] = s[fast_index++];
                }
            }
        }

        s.resize(slow_index);
    }

    string reverseWords(string s) {
        reverse(s, 0, s.size());
        removeExtraSpace(s);

        for(int fast_index=0, slow_index=0; fast_index < s.size(); fast_index++){
            if(s[fast_index] == ' '){
                reverse(s, slow_index, fast_index);
                slow_index = fast_index+1;
            }
                
        }

        return s;
    }
};
int main(){

    Solution s;

    string tst_s = "  hello world  ";

    cout << s.reverseWords(tst_s) <<endl;
    return 0;
}