#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummyHead = new ListNode(-101, head);
        ListNode* ppre = dummyHead;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != nullptr){
            if(cur->val == pre->val){
                while(cur != nullptr && cur->val == pre->val){
                    ListNode* next = cur->next;
                    // pre->next = next;
                    delete(cur);
                    cur = next;
                }
                ppre->next = cur;
                delete(pre);
                if(cur == nullptr) break;
                pre = cur;
                cur = cur->next;
            }
            else{
                ppre = pre;
                pre = cur;
                cur = cur->next;
            }
        }
        ListNode* r = dummyHead->next;
        delete(dummyHead);
        return r;
    }
};

int main() {

    return 0;
}