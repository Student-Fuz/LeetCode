#include <bits/stdc++.h>
using namespace std;

bool isNoZero(int n){
    while(n){
        int pos = n % 10;
        n /= 10;
        if(pos == 0) return false;
    }
    return true;
}

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(isNoZero(i) && isNoZero(n-i)){
                return {i, n-i};
            }
        }
        return {};
    }
};

int main() {

    return 0;
}