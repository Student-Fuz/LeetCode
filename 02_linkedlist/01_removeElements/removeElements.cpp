#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

// 注意删除非头部节点，要保留该节点的上一节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) { 
        ListNode *tmp;
        // 欲删除节点若在开头，删除头节点
        while(1){
            if(head == nullptr)
                return head;
            if(head->val == val){
                tmp = head;
                head = head->next;
                delete tmp;
            }
            else
                break;
        }
        // 欲删除非头节点若不在开头，需要记录目标节点cur的上一个节点prev
        ListNode *cur = head->next;
        ListNode *prev = head;
        while(1){
            if(cur == nullptr)
                break;
            if(cur->val == val){
                tmp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete tmp;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;

    }
};

// 打印函数
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// 将数组转换为链表的辅助函数
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main(){
    Solution s;
    int arr[] = {1,2,3,4,5,6,7,8};
    ListNode* head = createList(arr, sizeof(arr)/sizeof(int));
    cout << "The ListNode before" << endl;
    printList(head);
    // 删除节点3
    s.removeElements(head, 3);
    cout << "The ListNode after" << endl;
    printList(head);
    return 0;
}
