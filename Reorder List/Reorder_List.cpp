/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) //start to split it into two halves, the right should be less than the left;
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL, *node = slow, *next = NULL;
        while (node)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }

        ListNode *first = head, *second = prev;
        while (second->next)
        {
            ListNode *pfirst = first->next;
            ListNode *psecond = second->next;
            first->next = second;
            first = pfirst;
            second->next = first;
            second = psecond;
        }
        return;
    }
};

int main()
{
    Solution a;

    std::vector<int> arr{2, 3, 4, 5, 6, 7, 8};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    // p = new ListNode(1);
    for (auto i : arr)
    {
        // std::cout << "i = " << i << "\n";
        ListNode *next = new ListNode(i);
        p->next = next;
        // std::cout << "value = " <<p->val << "\n";
        p = next;
    }

    a.reorderList(head);

    ListNode *s1 = head;
    ListNode *s2 = s1;
    while (s2!= nullptr)
    {
        std::cout << s1->val << " ";
        s1 = s2->next;
        delete s2;
        s2 = s1;
        // if (s2 == nullptr) std::cout << "\n";
    }
    s1 = s2 = nullptr;

    return 0;
}