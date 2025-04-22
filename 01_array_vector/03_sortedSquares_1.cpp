#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// m1
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        for(const auto& num : nums){
            int r = num * num;
            result.push_back(r); 
        }
        sort(result.begin(), result.end());

        return result;
    }
};

// m2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int index = nums.size()-1;

        // 双指针
        // 自己设计特定排序方法
        for(int i = 0, j = nums.size()-1; i <= j;){
            if(abs(nums[i]) >= abs(nums[j])){
                result[index--] = nums[i]*nums[i];
                i++;
            }
            else{
                result[index--] = nums[j]*nums[j];
                j--;
            }
        }

        return result;
    }
};

int main(){ 
    Solution s;

    cout << endl;
    return 0;
}