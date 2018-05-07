/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.53%)
 * Total Accepted:    159.2K
 * Total Submissions: 474.6K
 * Testcase Example:  '[]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool recursive(struct ListNode* node, struct ListNode** head)
{
    bool ret = false;
    if (node->next) {
        ret = recursive(node->next, head);
    } else {
        ret = true;
    }
    ret = ret & (node->val == (*head)->val);

    *head = (*head)->next;
    return ret;
}

bool isPalindrome(struct ListNode* head)
{
    if (!head)
        return true;
    return recursive(head, &head);
}
