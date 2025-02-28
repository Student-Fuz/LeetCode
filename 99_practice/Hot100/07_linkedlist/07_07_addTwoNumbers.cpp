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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultDummyHead = new ListNode(0);
        ListNode* cur = resultDummyHead;

        int carry = 0;
        int num1 = 0;
        int num2 = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                num1 = 0;
                num2 = l2->val;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                num1 = l1->val;
                num2 = 0;
                l1 = l1->next;
            }
            else{
                num1 = l1->val;
                num2 = l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            int num = (num1 + num2 + carry)%10;
            cur->next = new ListNode(num);
            cur = cur->next; 
            carry = (num1 + num2 + carry)/10; 
        }
        if(carry)
            cur->next = new ListNode(1); 

        ListNode* result = resultDummyHead->next;
        delete resultDummyHead;
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}