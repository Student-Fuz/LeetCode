#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/reverse-string-ii/description/

class Solution {
public:
    string reverseStr(string s, int k) {
        int begin = 0;
        int cnt = 0;

        for(int i = 0; i < s.size(); i++){
            cnt++;
            if(cnt == 2*k){
                for(int j = 0; j < k/2;j++){
                    swap(s[begin+j], s[begin+k-1-j]);
                }
                begin = i+1;
                cnt = 0;
            }
        }

        if(cnt < k){
            int l = begin, r = s.size()-1;
            while(l < r){
                swap(s[l++], s[r--]);
            }
        }
        else{
            for(int j = 0; j < k/2;j++){
                swap(s[begin+j], s[begin+k-1-j]);
            }
        }
        return s;
    }
};

int main() {

    return 0;
}