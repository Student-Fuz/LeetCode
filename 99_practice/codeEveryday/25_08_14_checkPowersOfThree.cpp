#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int rem = 0;
        
        while(n > 0){
            rem = n % 3;
            n /= 3;
            if(rem == 2) return false;
        }

        return true;
    }
};

int main() {

    return 0;
}