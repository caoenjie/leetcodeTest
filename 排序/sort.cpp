#include <iostream>
#include <vector>


void quick_sort(std::vector<int>& nums, int l, int r) {
    if (l >= r) return;

    int pivot = nums[l];
    int i = l, j = r;

    while (i < j) {
        while (i < j && nums[j] >= pivot) --j;
        while (i < j && nums[i] <= pivot) ++i;
        if (i < j) std::swap(nums[i], nums[j]);
    }
    std::swap(nums[l], nums[i]);

    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
}

void merge_sort(std::vector<int>& nums, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    std::vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];

    for (int m = 0; m < temp.size(); ++m) {
        nums[l + m] = temp[m];
    }
}

void insert_sort(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

void bubble_sort(std::vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = 0; j < nums.size() - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void select_sort(std::vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }
}



int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};

    // quick_sort(arr, 0, arr.size() - 1);
    merge_sort(arr, 0, arr.size() - 1);
    // 输出排序后的数组
    for (const auto& num : arr) {
        std::cout << num << " ";
    }

    return 0;
}