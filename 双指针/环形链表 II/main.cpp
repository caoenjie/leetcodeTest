// https://leetcode-cn.com/problems/linked-list-cycle-ii/

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
*/

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
首先为何会第一圈就相遇, 假设 slow和fast在环起点开始,则,两圈后相遇
但实际fast必定比slow先进环,所以必定少于两圈,也就是说slow第一圈内就就会和fast相遇

a 为起始位置到入环口, b为slow 在环内的位置 c为fast此时到环节点的位置
slow * 2 = fast;
slow = a + b;
fast = a + b + c + b = a + 2*b + c;
(a + b)*2 = a + 2*b + c;
a = c;
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

       if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *slow = head->next, *fast = head->next->next;
        while(slow != fast) {
            if(!fast || !fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = head;
        while(fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};


int main() {


    return 0;
}