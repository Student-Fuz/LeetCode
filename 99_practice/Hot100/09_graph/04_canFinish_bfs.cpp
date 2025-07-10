#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> children(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++){
            children[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int visited = 0;
        while(!q.empty()){
            int cur = q.front();

            q.pop();

            visited++;

            for(int i = 0; i < children[cur].size(); i++){
                inDegree[children[cur][i]]--;
                if(inDegree[children[cur][i]] == 0){
                    q.push(children[cur][i]);
                }
            }
        }

        return visited == numCourses;

    }
};

int main() {

    return 0;
}