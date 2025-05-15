#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    ListNode* dummyHead;
    int size = 0;

public:
    MyLinkedList() {
        dummyHead = new ListNode(0, nullptr);
    }
    
    int get(int index) {
        if(index > size-1)
            return -1;

        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead->next;
        for(int i = 0; i < index; i++){
            pre = cur;
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = dummyHead->next;
        dummyHead->next = new ListNode(val, tmp);
        dummyHead->next = dummyHead->next;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead->next;
        while(cur != NULL){
            pre = cur;
            cur = cur->next;
        }
        cur = new ListNode(val);
        pre->next = cur;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
            return;

        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead->next;
        for(int i = 0; i < index; i++){
            pre = cur;
            cur = cur->next;
        }
        ListNode* tmp = cur;
        cur = new ListNode(val);
        cur->next = tmp;
        pre->next = cur;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
            return;

        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead->next;
        for(int i = 0; i < index; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
        size--;
    }
};
    

int main() {

    return 0;
}