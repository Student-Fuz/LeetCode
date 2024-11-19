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
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow_node = head;
        ListNode *fast_node = head;

        int distance = 0;

        while(1){
            if(distance < n){
                if(fast_node != nullptr)
                    fast_node = fast_node->next;
                distance++;
            }
            else{
                while(fast_node != nullptr){
                    fast_node = fast_node->next;
                    slow_node = slow_node->next;
                }
            }
        }
        
    }
};;

int main(){

    Solution s;

    return 0;
}