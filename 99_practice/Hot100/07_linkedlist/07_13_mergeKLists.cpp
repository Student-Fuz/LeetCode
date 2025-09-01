#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        int emptyNum = 0;
        for(const auto& node : lists){
            if(node == nullptr) emptyNum++;
        }
        while(1){
            if(emptyNum==lists.size()) break;
            int minVal = INT_MAX;
            int index = -1;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val < minVal){
                    minVal = lists[i]->val;
                    index = i;
                }
            } 
            cur->next = lists[index];
            cur = cur->next;
            lists[index] = lists[index]->next;
            if(lists[index] == nullptr) emptyNum++;
        }
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

// 错误
//ListNode*&  can = lists[0];--->can是lists[0]的别名
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        int emptyNum = 0;
        for(const auto& node : lists){
            if(node == nullptr) emptyNum++;
        }
        while(1){
            if(emptyNum==lists.size()) break;
            int minVal = INT_MAX;
            ListNode*& can = lists[0];
            // for(auto& node : lists){
            //     if(node != nullptr && node->val < minVal){
            //         minVal = node->val;
            //         can = node;
            //     }
            // } 
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val < minVal){
                    minVal = lists[i]->val;
                    can = lists[i];
                }
            } 
            cur->next = can;
            cur = cur->next;
            can = can->next;
            if(can == nullptr) emptyNum++;
        }
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};





// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
//         if ((!a) || (!b)) return a ? a : b;
//         ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//         while (aPtr && bPtr) {
//             if (aPtr->val < bPtr->val) {
//                 tail->next = aPtr; aPtr = aPtr->next;
//             } else {
//                 tail->next = bPtr; bPtr = bPtr->next;
//             }
//             tail = tail->next;
//         }
//         tail->next = (aPtr ? aPtr : bPtr);
//         return head.next;
//     }

// };

int main() {

    return 0;
}