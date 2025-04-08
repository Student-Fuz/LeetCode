#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked


struct DLinkedNode{
    // 需要有key, 以便删除结尾时删除哈希表中的键值对
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

// Solution
class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            // 将节点放在前面
            move_to_front(cache[key]);
            return cache[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            // 将节点放在前面
            move_to_front(cache[key]);
            cache[key]->value = value;
            return;
        }
        else{
            // 构造节点放在队头
            DLinkedNode* newNode = new DLinkedNode(key, value);
            push_front(newNode);
            cache[key] = newNode;
            size++;
            if (size > capacity) {
                pop_end();
            }
        }
    }

    void move_to_front(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        node->next = head->next;
        node->prev = head;

        head->next = node;
        node->next->prev = node;
    }

    void push_front(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void pop_end(){
        DLinkedNode* node = tail->prev;
        // remove from map
        cache.erase(node->key);
        // detach
        node->prev->next = tail;
        tail->prev = node->prev;
        delete node;
        size--;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}