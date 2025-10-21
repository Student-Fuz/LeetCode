#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> r;
        for(int i = 0; i < n/2; i++){
            r.push_back(i+1);
            r.push_back(-i-1);
        }
        if(n%2) r.push_back(0);
        return r;
    }
};

int main() {

    return 0;
}