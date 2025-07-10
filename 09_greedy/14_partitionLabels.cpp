#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/partition-labels/

/* 
心里默念：
片段尽可能地多
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ends(26, 0);

        for(int i = 0; i < s.size(); i++){
            ends[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end, ends[s[i] - 'a']);
            if(i == end){
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};

int main() {

    return 0;
}