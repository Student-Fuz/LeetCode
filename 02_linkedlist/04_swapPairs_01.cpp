#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;

        while(cur != nullptr && cur->next != nullptr && cur->next->next != nullptr){
            ListNode* node1 = cur->next;
            ListNode* node2 = cur->next->next;
            node1->next = node2->next;
            node2->next = node1;
            cur->next = node2;
            cur = node1;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

int main() {

    return 0;
}