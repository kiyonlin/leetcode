/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.68%)
 * Total Accepted:    485.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    struct ListNode* cur = NULL;
    int hold = 0;

    while (l1 != NULL || l2 != NULL || hold != 0) {
        if (cur == NULL)
            cur = result;
        else {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur->next->val = 0;
            cur = cur->next;
        }

        cur->val += hold;

        if (l1 != NULL) {
            cur->val += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            cur->val += l2->val;
            l2 = l2->next;
        }

        hold = cur->val / 10;

        cur->val %= 10;
        cur->next = NULL;
    }
    return result;
}
