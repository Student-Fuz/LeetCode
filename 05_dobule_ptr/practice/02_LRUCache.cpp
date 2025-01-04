#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 题目描述


// Solution
// 错误示范 不应该使用队列
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            myQueue.push(key);
            // 注意如果查找的元素在里面队列里怎么办？
            if(myQueue.size() > capacity)
                myQueue.pop();
            return cache[key];
        }
            
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            cache[key] = value;
        else{
            if(myQueue.size() == capacity){
                int deleted = myQueue.front();
                myQueue.pop();
                cache.erase(deleted);
            }
            myQueue.push(key);
            cache[key] = value;
        }
    }

private: 
    unordered_map<int, int> cache;
    queue<int> myQueue;
    int capacity = 0;
};

// 正确做法：
// 应该使用双向链表
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            myQueue.push(key);
            // 注意如果查找的元素在里面队列里怎么办？
            if(myQueue.size() > capacity)
                myQueue.pop();
            return cache[key];
        }
            
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            cache[key] = value;
        else{
            if(myQueue.size() == capacity){
                int deleted = myQueue.front();
                myQueue.pop();
                cache.erase(deleted);
            }
            myQueue.push(key);
            cache[key] = value;
        }
    }

private: 
    unordered_map<int, int> cache;
    queue<int> myQueue;
    int capacity = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    return 0;
}