#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2025-07-23

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string st;
        char c1 = 'a', c2 = 'b';
        if(x < y){
            c1 = 'b';
            c2 = 'a';
        }
        int h = max(x, y);
        int l = min(x, y);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c2 && !st.empty() && st.back() == c1){
                res += h;
                st.pop_back();
            }else{
                st.push_back(s[i]);
            }
        }
        string st_1;
        for(int i = 0; i < st.size(); i++){
            if(st[i] == c1 && !st_1.empty() && st_1.back() == c2){
                res += l;
                st_1.pop_back();
            }else{
                st_1.push_back(st[i]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}