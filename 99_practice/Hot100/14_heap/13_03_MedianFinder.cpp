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
// https://leetcode.cn/problems/find-median-from-data-stream/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 自写堆排序
class MedianFinder {
private:
    // queMin--存放小于等于中位数的值； queMax--存放发育中位数的值；
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

public:
    MedianFinder() {
            
    }

    void addNum(int num) {
        if(queMin.size() == 0)
            queMin.push(num);
        else if(num <= queMin.top()){
            if(queMin.size() == queMax.size()){
                queMin.push(num);
            }
            else{
                queMax.push(queMin.top());;
                queMin.pop();
                queMin.push(num);
            }
        }
        else{
            if(queMin.size() == queMax.size()){
                queMax.push(num);
                queMin.push(queMax.top());
                queMax.pop();
            }
            else{
                queMax.push(num);
            }
        }
    }
    
    double findMedian() {
        if(queMin.size() == 0)
            return 0;
        else if(queMin.size() == queMax.size()){
            return (queMin.top()+queMax.top())/2.0;
        }
        else{
            return queMin.top();
        }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}