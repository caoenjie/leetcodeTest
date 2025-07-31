这个分支以算法为主，数据结构为辅的形式进行练习，题目均来自leetcode

# 贪心算法
保证局部最优的情况，得到全局最优

455.[分发饼干](https://leetcode-cn.com/problems/assign-cookies/)

135.[分发糖果](https://leetcode-cn.com/problems/candy/)

435.[无重叠区间](https://leetcode-cn.com/problems/non-overlapping-intervals/)

605.[种花问题](https://leetcode-cn.com/problems/can-place-flowers/)

452.[用最少数量的箭引爆气球](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)

763.[划分字母区间](https://leetcode-cn.com/problems/partition-labels/)

122.[买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

406.[根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

665.[非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)

# 双指针
双指针指的是在一个数据结构上同时使用两个指针（索引）来遍历、查找、比较或移动，以达到比单指针更高效的目的。
| 类型       | 描述             | 举例用途                |
| -------- | -------------- | ------------------- |
| **对撞指针** | 一头一尾，向中间靠拢     | 判断是否是回文串、两数之和（有序数组） |
| **快慢指针** | 一个指针走得快，一个慢    | 链表找环、删除重复元素、滑动窗口    |
| **滑动窗口** | 两个指针控制子数组/子串范围 | 最长子串、最小覆盖子串、子数组和问题  |


167.[两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

88.[合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

633.[平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)

680.[验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)

345.[反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

142.[环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

76.[最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

524.[通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

# 二分查找
用于有序数据中查找目标值。每次将搜索范围折半，直到找到目标或搜索区间为空

69.[Sqrt(x)](https://leetcode-cn.com/problems/sqrtx/)

34.[在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

81.[搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

154.[寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

540.[有序数组中的单一元素](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)

4.[寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

# 排序算法
🧩 一、比较类排序算法
| 算法                   | 最坏时间复杂度      | 平均时间复杂度    | 空间复杂度    | 是否稳定 | 适用场景       |
| -------------------- | ------------ | ---------- | -------- | ---- | ---------- |
| 冒泡排序（Bubble Sort）    | O(n²)        | O(n²)      | O(1)     | ✅    | 教学用或数据近乎有序 |
| 插入排序（Insertion Sort） | O(n²)        | O(n²)      | O(1)     | ✅    | 小规模数据/基本有序 |
| 选择排序（Selection Sort） | O(n²)        | O(n²)      | O(1)     | ❌    | 简单但效率低     |
| 希尔排序（Shell Sort）     | O(n^1.3\~n²) | O(n^1.5)   | O(1)     | ❌    | 插入排序的改进    |
| 归并排序（Merge Sort）     | O(n log n)   | O(n log n) | O(n)     | ✅    | 大规模、稳定要求   |
| 快速排序（Quick Sort）     | O(n²)        | O(n log n) | O(log n) | ❌    | 最常用的高效排序   |
| 堆排序（Heap Sort）       | O(n log n)   | O(n log n) | O(1)     | ❌    | 不稳定但空间效率好  |

🔢 二、非比较类排序算法（适用于整数等有限范围）
| 算法                  | 时间复杂度     | 空间复杂度    | 是否稳定 | 特点         |
| ------------------- | --------- | -------- | ---- | ---------- |
| 计数排序（Counting Sort） | O(n + k)  | O(k)     | ✅    | 数据范围小、正整数  |
| 桶排序（Bucket Sort）    | O(n + k)  | O(n + k) | ✅    | 数据分布均匀时高效  |
| 基数排序（Radix Sort）    | O(n \* k) | O(n + k) | ✅    | 适合定长整数或字符串 |

215.[数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/)

347.[前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/description/)

451.[根据字符出现频率排序](https://leetcode.cn/problems/sort-characters-by-frequency/description/)

75.[颜色分类](https://leetcode.cn/problems/sort-colors/)