class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    MyLinkedList() {
        // 链表技巧---设置虚拟头节点 
        // 注意在堆区申请的内存，需要释放！！！对象消亡，该内存也被释放
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        // for(int i = 0; i < index; i++){
        //     cur = cur->next;
        // }
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val); 
        newHead->next = _dummyHead->next;
        _dummyHead->next = newHead;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* cur = _dummyHead;
        LinkedNode* newTail = new LinkedNode(val);
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newTail;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index < 0) index = 0; 
        LinkedNode* prev = _dummyHead;
        LinkedNode* cur = _dummyHead->next;
        for(int i = 0; i < index; i++){
            prev = cur;
            cur = cur->next;
        }
        LinkedNode* newNode = new LinkedNode(val);
        prev->next = newNode;
        newNode->next = cur;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index > (_size-1) || index < 0) {
            return;
        }
        LinkedNode* prev = _dummyHead;
        LinkedNode* cur = _dummyHead->next;
        for(int i = 0; i < index; i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        _size--;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    // 动态分配(堆分配)
    MyLinkedList* a = new MyLinkedList();
    a->addAtHead(8);
    a->addAtTail(9);
    // 静态分配(栈分配)
    MyLinkedList b;
    b.addAtHead(8);
    b.addAtTail(9);

    return 0;
}