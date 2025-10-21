#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18

class MyCmp{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        if(a[2] == b[2]) return a[1] < b[1];
        return a[2] < b[2];
    }
};

// 双向链表+哈希
class TaskManager {
private:
    priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
    unordered_map<int, vector<int>> map;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task : tasks){
            pq.push(task);
            map[task[1]] = {task[0], task[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.emplace(vector<int>({userId, taskId, priority}));
        map[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        if(map.find(taskId) == map.end()) return;
        map[taskId][1] = newPriority;
        pq.emplace(vector<int>({map[taskId][0], taskId, newPriority}));
    }
    
    void rmv(int taskId) {
        map.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            int userId = pq.top()[0], taskId = pq.top()[1], p = pq.top()[2];
            pq.pop();

            if  (map.find(taskId) != map.end() && 
                map[taskId][1] == p){
                userId = map[taskId][0];
                map.erase(taskId);
                return userId;
            }

        }
        return -1;
        
    }
};


int main() {

    return 0;
}