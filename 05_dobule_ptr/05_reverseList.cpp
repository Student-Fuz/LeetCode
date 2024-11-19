#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // // 三指针(其实也是双指针)
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *next;
    //     ListNode *cur = head;
    //     ListNode *prev = nullptr;
    //     while(cur != nullptr){
    //         next = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;
    //     }
    //     return prev;
    // }

    // 双指针 
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while(cur != nullptr){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};


int main(){

    Solution s;

    return 0;
}