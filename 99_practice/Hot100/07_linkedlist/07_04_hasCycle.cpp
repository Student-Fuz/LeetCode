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

// Solution
// 哈希
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;

        ListNode* cur = head;
        while(cur != NULL){
            if(nodeSet.find(cur) != nodeSet.end())
                return true;
            nodeSet.insert(cur);
            cur = cur->next;
        }

        return false;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}