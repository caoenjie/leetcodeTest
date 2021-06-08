/**
 * https://leetcode.com/problems/add-two-numbers/
 * Definition if singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(NULL);
        ListNode *prev = head;
        ListNode *node;
        int sum = 0;
        while(l1 || l2 || sum)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum +=l2->val;
                l2 = l2->next;
            }
            node = new ListNode(sum % 10);
            prev->next = node;
            prev = node;
            sum /= 10;
        }
        return head->next;
    }
};

// std::pair<std::string, std::string> f(std::pair<std::string, std::string> p)
// {
//     return {p.second, p.first}; // list-initialization in return statement
// }

int main()
{
    // int a(2);
    // cout << "a = "<< a <<"\n";
    // struct ListNode *node = new ListNode(2);
    // cout << "node val = "<< node->val <<"\n";

    // cout << f({"hello", "world"}).first <<"\n";
    return 0;
}