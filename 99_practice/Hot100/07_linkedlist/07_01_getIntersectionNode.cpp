#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// 暴力查找
// Solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA != NULL){
            curB = headB;
            while(curB != NULL){
                if(curB == curA){
                    return curB;
                }
                curB = curB->next;
            }
            curA = curA->next;
        }
        return nullptr;
    }
};

// 优化版本
// 哈希表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;

        unordered_set<ListNode*> nodeMap;

        while(curA != NULL){
            nodeMap.insert(curA);
            curA = curA->next;
        }

        while(curB != NULL){
            if(nodeMap.count(curB))
                return curB;
            curB = curB->next;
        }

        return nullptr;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}