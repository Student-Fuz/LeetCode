#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/swap-nodes-in-pairs/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// Solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == nullptr)
            return head;

        ListNode* pre;
        ListNode* cur;
        ListNode* next;

        ListNode* result;

        pre = head;
        result = cur = head->next;


        while(true){
            next = cur->next;
            cur->next = pre;
            cur = next;
            // 偶数个节点 结尾处
            if(cur == NULL){
                pre->next = nullptr;
                break;
            }
            // 奇数个节点 结尾处
            else if(cur->next == nullptr){
                pre->next = cur;
                break;
            }
            pre->next = cur->next;
            pre = cur;
            cur = cur->next;
        }
        return result;
    }
};

// Solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == nullptr)
            return head;

        ListNode* pre;
        ListNode* cur;
        ListNode* next;

        ListNode* result;

        pre = head;
        result = cur = head->next;


        while(true){
            next = cur->next;
            cur->next = pre;
            cur = next;
            // 偶数个节点 结尾处
            if(cur == NULL || cur->next == nullptr){
                pre->next = cur;
                break;
            }
            pre->next = cur->next;
            pre = cur;
            cur = cur->next;
        }
        return result;
    }
};

int main(){

    // 创建链表 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution s;

    ListNode* newHead = s.swapPairs(head);

    cout << "Hello, world!" << endl;

    return 0;
}