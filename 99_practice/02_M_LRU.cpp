#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/lru-cache/description/

// Solution
// hash表+双向链表
struct DLinkedNode{
    // 需要有key, 以便删除结尾时删除哈希表中的键值对
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(cache.find(key) != cache.end()){
            // 放到双向链表头部
            move_to_front(cache[key]);
            return cache[key]->value;
        }
        else
            return -1;
    }

    void put(int key, int value){
        if(cache.find(key) != cache.end()){
            cache[key]->value = value;
            // 修改值，放到双向链表头部
            move_to_front(cache[key]);
        }
        else{
            // 创建新节点
            DLinkedNode* newNode = new DLinkedNode(key, value);
            // 哈希表新增
            cache[key] = newNode;
            if(size == capacity){
                push_front(newNode);
                cache.erase(tail->prev->key);
                pop_end();
            }
            else{
                push_front(newNode);
                size++;
            }
        }
    }

    void push_front(DLinkedNode* DLNode){
        DLNode->next = head->next;
        DLNode->next->prev = DLNode;
        head->next = DLNode;
        DLNode->prev = head;
    }

    void pop_end(){
        DLinkedNode* end = tail->prev->prev;
        end->next = tail;
        delete(tail->prev);
        tail->prev = end;
    }

    void move_to_front(DLinkedNode* DLNode){
        // 删除前后链接
        DLNode->prev->next = DLNode->next;
        DLNode->next->prev = DLNode->prev;
        push_front(DLNode);
    }
};


int main(){

    Solution s;

    return 0;
}