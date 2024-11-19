#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 0};

    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
