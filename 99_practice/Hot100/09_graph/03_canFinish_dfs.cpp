#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        // 0-unsearched; 1-searching; 2-searched.
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};

// m1: dfs
class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<int>& visited, bool& valid, int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(edges, visited, valid, v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 0-unsearched; 1-searching; 2-searched.
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses, 0);
        bool valid;
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(edges, visited, valid, i);
            }
        }
        return valid;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<int>& visited, vector<int>& result, bool& valid, int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(edges, visited, result, valid, v);
                if (!valid) return;
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
        result.push_back(u); // 加入栈（实际上我们用数组模拟栈）
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> result;
        bool valid = true;

        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i) {
            if (visited[i] == 0) {
                dfs(edges, visited, result, valid, i);
            }
        }

        if (!valid) return {};  // 有环，返回空

        reverse(result.begin(), result.end());  // 反转得到正确顺序
        return result;
    }
};
    
    


int main() {

    return 0;
}