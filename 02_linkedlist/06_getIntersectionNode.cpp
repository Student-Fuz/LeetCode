#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 思路：
// 将一个链表的所有节点以哈希表存储
// 从头开始遍历另一个节点
// 时间复杂度O(m+n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        unordered_set<ListNode*> nodeSet;

        while(cur != NULL){
            nodeSet.insert(cur);
            cur = cur->next;
        }

        cur = headB;
        while(cur != NULL){
            if(nodeSet.find(cur) != nodeSet.end())
                return cur;
            cur = cur->next;
        }

        return cur;
    }
};

// 思路二：
// 双指针
// ptrA遍历 A_self、AB_public、B_self段
// prtB遍历 B_self、AB_public、A_self段

// 时间复杂度O(m+n)
// 空间复杂度O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(1){
            if(ptrA == ptrB)
                return ptrA;
            ptrA = (ptrA == NULL) ? headB : ptrA->next;
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }
    }
};

// 错误双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(1){
            if(ptrA == ptrB)
                return ptrA;
            // 当ptr为NULL时，ptr向前走了两步！！！（严重错误）
            if(ptrA == NULL)
                ptrA = headB;
            if(ptrB == NULL)
                ptrB = headA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
};


int main() {

    return 0;
}