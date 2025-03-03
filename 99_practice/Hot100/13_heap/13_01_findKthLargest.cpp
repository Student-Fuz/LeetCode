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

// 现成堆数据结构 priority_queue


// m1: 基于快速排序的选择方法
class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r)
            return nums[k];

        // 以nums[l]为基准进行排序--开始
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            // 第i个数的值大于等于了基准；第j个数的值小于等于了基准
            if (i < j)
                swap(nums[i], nums[j]);
        }
        // 以nums[l]为基准进行排序--结束 
        // nums[l]的位置是？---> 
        // 1. i == j时，为i/j;
        // 2. i > j 时，为i 或者 j

        // m1 : j 或者 j+1 是排好位置的元素
        // if (k <= j) return quickselect(nums, l, j, k);
        // else return quickselect(nums, j + 1, r, k);

        // m2: i 或者 i-1 是排好位置的元素
        if (k <= i-1) return quickselect(nums, l, i-1, k);
        else return quickselect(nums, i, r, k);
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
        int pivot = arr[high]; 
        int i = low - 1;

        // 双指针
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++; 
                std::swap(arr[i], arr[j]); 
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1; 
    }

    void find(std::vector<int>& arr, int low, int high, int k, int& result) {
        if (low <= high) {
            int pi = partition(arr, low, high);

            if(pi == k){
                result = arr[pi];
                return;
            }
            if(pi > k){
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
        find(nums, 0, nums.size()-1, nums.size() - k, result);
        return result;
    }
};

// try2
// 分区函数，返回基准元素的位置
class Solution {
private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[low]; 
        int i = high + 1;

        // 双指针
        for (int j = high; j > low; j--) {
            if (arr[j] >= pivot) {
                i--; 
                std::swap(arr[i], arr[j]); 
            }
        }
        std::swap(arr[i - 1], arr[low]);
        return i - 1; 
    }

    void find(std::vector<int>& arr, int low, int high, int k, int& result) {
        if (low <= high) {
            int pi = partition(arr, low, high);

            if(pi == k){
                result = arr[pi];
                return;
            }
            if(pi > k){
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
        find(nums, 0, nums.size()-1, nums.size() - k, result);
        return result;
    }
};

// 堆排序
class solution{
private:
    // 调整堆，使其满足大顶堆的性质
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i; // 初始化最大值为根节点
        int left = 2 * i + 1; // 左子节点
        int right = 2 * i + 2; // 右子节点

        // 如果左子节点大于根节点
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // 如果右子节点大于当前最大值
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // 如果最大值不是根节点
        if (largest != i) {
            std::swap(arr[i], arr[largest]);

            // 递归调整受影响的子树
            heapify(arr, n, largest);
        }
    }
public:
    // 堆排序函数
    void heapSort(std::vector<int>& arr) {
        int n = arr.size();

        // 构建大顶堆（从最后一个非叶子节点开始）
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 逐个提取堆顶元素并调整堆
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]); // 将堆顶元素与末尾元素交换
            heapify(arr, i, 0); // 调整剩余元素为大顶堆
        }
    }
};


// 基于堆排序的选择方法
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

class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};
    

int main(){

    Solution s;

    return 0;
}