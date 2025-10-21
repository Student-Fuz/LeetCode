#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSize(int num){
        int size = 0;
        while(num != 0){
            num /= 10;
            size++;
        }
        return size;
    }
    int findNumbers(vector<int>& nums) {
        int r = 0;
        for(auto num : nums){
            if(!(digitSize(num)%2)) r++;
        }
        return r;
    }
};

int main() {

    return 0;
}