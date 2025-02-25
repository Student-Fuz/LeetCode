#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        ListNode* dummyHead = newList;
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL || list1->val >= list2->val){
                newList->next = new ListNode(list2->val);
                newList = newList->next;
                list2 = list2->next;
                continue;
            }
            if(list2 == NULL || list2->val >= list1->val){
                newList->next = new ListNode(list1->val);
                newList = newList->next;
                list1 = list1->next;
                continue;
            }
        }
        return dummyHead->next;
    }
};

// Solution
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* newList = new ListNode();
            ListNode* dummyHead = newList;
            while(list1 != NULL || list2 != NULL){
                if(list1 == NULL){
                    newList->next = new ListNode(list2->val);
                    newList = newList->next;
                    list2 = list2->next;
                    continue;
                }
                if(list2 == NULL){
                    newList->next = new ListNode(list1->val);
                    newList = newList->next;
                    list1 = list1->next;
                    continue;
                }
                if(list1->val >= list2->val){
                    newList->next = new ListNode(list2->val);
                    newList = newList->next;
                    list2 = list2->next;
                    continue;
                }
                if(list1->val >= list2->val){
                    newList->next = new ListNode(list2->val);
                    newList = newList->next;
                    list2 = list2->next;
                    continue;
                }
            }
            return dummyHead->next;
        }
    };



int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}