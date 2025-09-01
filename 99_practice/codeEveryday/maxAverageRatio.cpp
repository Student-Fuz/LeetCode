#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01

class MyCmp{
public:
    bool operator()(vector<int>& l, vector<int>& r){
        double gainL = (double)(l[0] + 1) / (l[1] + 1) - (double)l[0] / l[1];
        double gainR = (double)(r[0] + 1) / (r[1] + 1) - (double)r[0] / r[1];
        return gainL < gainR;  // 大根堆：增益大的排在前面
        // return l[1] > r[1];
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ratio = 0;
        priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
        for(int i = 0; i < classes.size(); i++){
            if(classes[i][0] != classes[i][1])
                pq.push(classes[i]);
            else
                ratio += 1.0;
        }
        if(pq.empty()) return 1.0;

        while(extraStudents != 0){
            vector<int> top = pq.top();
            pq.pop();
            extraStudents--;
            top[0]++, top[1]++;
            pq.push(top);
        }

        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            ratio += double(top[0])/double(top[1]);
        }

        return ratio / classes.size();
    }
};

int main() {

    priority_queue<vector<int>, vector<vector<int>>, MyCmp> pq;
    pq.push({1, 2});
    pq.push({3, 4});

    cout << pq.top()[0] << endl;

    return 0;
}