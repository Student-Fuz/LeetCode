#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-03

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int num = 0;

        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                for(int k = 0; k < points.size(); k++){
                    if(k != i && k != j){
                        
                    }
                }
            }
        }

        return num;
    }
};

int main() {

    return 0;
}