#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 两遍扫描
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int size = 0;
        while(cur != nullptr){
            cur = cur->next;
            size++;
        }

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;
        cur = head;
        for(int i = 0; i < size - n; i++){
            pre = pre->next;
            cur = cur->next;
        }

        pre->next = cur->next;
        delete cur;
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

// 一遍扫描
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;

        // 1. 将pre与cur之间的距离拉至n+1
        for(int i = 0; i < n; i++){
            cur = cur->next;
        }

        // 2. 同时后移，直到cur为null
        while(cur != NULL){
            pre = pre->next;
            cur = cur->next;
        }

        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
    

int main() {

    return 0;
}