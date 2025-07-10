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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);

        ListNode* pre = dummyHead;
        ListNode* cur = head;

        while(cur != NULL){
            if(cur->val == val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {

    return 0;
}