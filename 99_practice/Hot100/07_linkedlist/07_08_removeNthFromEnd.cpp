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
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode* dummyHead = new ListNode(0, head);

        int len = 0;

        ListNode* cur = head;
        while(cur != NULL){
            len++;
            cur = cur->next;
        }

        int m = len - n;
        cur = dummyHead;
        while(m > 0){
            m--;
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete(tmp);

        ListNode* result = dummyHead->next;
        delete(dummyHead);
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}