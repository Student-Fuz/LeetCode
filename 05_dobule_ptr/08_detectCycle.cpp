#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

 

// 示例 1：

// 输入：haystack = "sadbutsad", needle = "sad"
// 输出：0
// 解释："sad" 在下标 0 和 6 处匹配。
// 第一个匹配项的下标是 0 ，所以返回 0 。
// 示例 2：

// 输入：haystack = "leetcode", needle = "leeto"
// 输出：-1
// 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 

// 提示：

// 1 <= haystack.length, needle.length <= 104
// haystack 和 needle 仅由小写英文字符组成


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // hashtable法
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> node_set;
        ListNode* cur = head;
        while(cur != nullptr){
            if(node_set.find(cur) != node_set.end())
                return cur;
            else{
                node_set.insert(cur);
                cur = cur->next;
            }   
        }
        return nullptr;
    }

    // 双指针法 fast 一次移动两个节点，slow 一次移动一个节点
};

int main(){

    Solution s;

    return 0;
}