#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* begin = dummyHead;
        ListNode* cur = head;
        ListNode* pre;
        ListNode* end = head;

        for(int i = 0; i < left-1; i++){
            begin = begin->next;
            cur = cur->next;
        }

        for(int i = 0; i < right; i++){
            end = end->next;
        }

        ListNode* next = cur->next;
        cur->next = end;
        pre = cur;
        cur = next;
        while(cur != end){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        begin->next = pre;

        ListNode* r = dummyHead->next;
        delete(dummyHead);
        return r;
    }
};

int main() {

    return 0;
}
