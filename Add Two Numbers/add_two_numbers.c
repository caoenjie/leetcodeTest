/**
 * Definition for singly-linked list.
 */
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */


#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = head;
    struct ListNode *node;
    
    int number = 0;
    while (l1 || l2 || number)
    {
        if(l1)
        {
            number += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            number += l2->val;
            l2 = l2->next;
        }
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = number % 10;
        prev->next = node;
        prev = node;
        number /= 10;
    }
    prev->next = NULL;
    return head->next;
}


int main()
{
    return 0;
}