#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/linked-list-cycle-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;
        ListNode* cur = head;

        while(cur != NULL){
            if(nodeSet.count(cur) != 0)
                return cur;
            nodeSet.insert(cur);
            cur = cur->next;
        }

        return NULL;
    }
};

int main() {

    return 0;
}