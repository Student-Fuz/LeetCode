#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // 暴力解法
    // 时间复杂度O(mn)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    //     ListNode *itNodeA_fast = headA;
    //     ListNode *itNodeA_slow = headA;
    //     ListNode *itNodeB = headB;

    //     while(1){
    //         itNodeB = headB;
    //         while(itNodeB != nullptr && itNodeA_fast != itNodeB)
    //             itNodeB = itNodeB->next;
    //         if(itNodeB == nullptr){
    //             if(itNodeA_slow != nullptr){
    //                 itNodeA_slow = itNodeA_slow->next;
    //                 itNodeA_fast = itNodeA_slow;
    //             }
    //             else
    //                 break;
    //         }
    //         else
    //             break;
    //     }
    //     return itNodeA_fast;
    // }

    // 细腻方法
    // 时间复杂度O(m + n)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB; 
        int lenA = 0, lenB = 0;

        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }

        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让A为更长的链表
        if(lenA < lenB){
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;
        while(gap--)
            curA = curA->next;

        while(curA != nullptr && curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};

int main(){

    Solution s;
    return 0;
}