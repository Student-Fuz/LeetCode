#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=top-100-liked

// Solution
// 不懂算法的写法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// m1: 基于快速排序的选择方法
class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r)
            return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)return quickselect(nums, l, j, k);
        else return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};


// try1
// 分区函数，返回基准元素的位置
class Solution {
private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // 选择最右边的元素作为基准
        int i = low - 1; // i 是小于等于 pivot 的元素的区域的边界

        for (int j = low; j < high; j++) {
            // 如果当前元素小于或等于基准
            if (arr[j] <= pivot) {
                i++; // 增加小于等于基准区域的边界
                std::swap(arr[i], arr[j]); // 将当前元素与小于等于基准区域的第一个元素交换
            }
        }
        // 将基准元素放到正确的位置
        std::swap(arr[i + 1], arr[high]);
        return i + 1; // 返回基准元素的位置
    }

    // 快速排序函数
    // 区间左闭右闭
    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // 找到基准元素的位置
            int pi = partition(arr, low, high);

            // 对基准元素左边的部分排序
            quickSort(arr, low, pi - 1);
            // 对基准元素右边的部分排序
            quickSort(arr, pi + 1, high);
        }
    }

    void find(std::vector<int>& arr, int low, int high, int k, int& result) {
        if (low <= high) {
            // 找到基准元素的位置
            int pi = partition(arr, low, high);

            if(pi == arr.size() - k){
                result = arr[pi];
                return;
            }
            if(pi > arr.size() - k){
                find(arr, low, pi - 1, k, result);
            }
            else{
                find(arr, pi + 1, high, k, result);
            }
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int result = 0;
        find(nums, 0, nums.size()-1, k, result);
        return result;
    }
};

// 堆排序
class Solution {
public:
    // 递归调整最大堆
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;       // 当前节点索引
        int left = 2 * i + 1;  // 左子节点索引
        int right = 2 * i + 2; // 右子节点索引

        // 比较左子节点和当前节点
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        // 比较右子节点和当前节点
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        // 若最大值不是当前节点，交换并递归调整
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest); // 递归调整子树
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. 构建最大堆（从最后一个非叶子节点开始）
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(nums, n, i);
        }

        // 2. 提取前 K 个最大值（交换堆顶到末尾，缩小堆范围）
        for (int i = n - 1; i >= n - k; --i) {
            swap(nums[0], nums[i]); // 堆顶（最大值）交换到末尾
            heapify(nums, i, 0);    // 调整剩余堆
        }

        return nums[n - k]; // 第 K 大元素位于 n - k 位置
    }
};

int main(){

    Solution s;

    return 0;
}