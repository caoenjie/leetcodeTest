# https://leetcode.com/problems/reorder-list/
# Definition for singly-linked list.
'''
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
'''


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head:
            return None
        # set slow to mid for odd length, first of second half for even
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        prev, node = None, slow
        while node:
            prev, node.next, node = node, prev, node.next

        first, second = head, prev

        while second.next:
            first.next, first = second, first.next
            second.next, second = first, second.next


if __name__ == "__main__":
    head = ListNode(1)
    next_node = head
    l = [2, 3, 4, 5, 6, 7, 8]

    for i in l:
        node = ListNode(i)
        next_node.next = node
        next_node = next_node.next

    n = head
    while n:
        print(n.val, end=" ")
        n = n.next

    print('')
    print("reorder list")
    s = Solution()
    s.reorderList(head)

    while head:
        print(head.val, end=" ")
        head = head.next
