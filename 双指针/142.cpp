#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * 相遇的时候 快指针比慢指针多走了N圈环，此时慢指针移动到头节点
 * 同时移动，快指针到达环起点的距离等于满指针走到环起点的距离加上N圈
 *
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *p = head->next, *n = head->next->next;
        while(p != n) {
            if(n == nullptr || n->next == nullptr) return nullptr;
            p = p->next;
            n = n->next->next;
        }
        n = head;
        while(p != n) {
            p = p->next;
            n = n->next;
        }
        return n;
    }
};