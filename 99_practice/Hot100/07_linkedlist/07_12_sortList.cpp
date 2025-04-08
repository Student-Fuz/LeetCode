#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked

// Definition for a Node.
struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// 转换成数组进行处理
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vec;

        ListNode* cur = head;
        while(cur != NULL){
            vec.push_back(cur->val);
            cur = cur->next;
        }

        sort(vec.begin(), vec.end());

        cur = head;
        int i = 0;
        while(cur != NULL){
            cur->val = vec[i++];
            cur = cur->next;
        }

        return head;
    }
};

// 自己写快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {

    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}