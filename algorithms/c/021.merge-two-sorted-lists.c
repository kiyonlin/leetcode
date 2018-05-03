/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (41.29%)
 * Total Accepted:    343.8K
 * Total Submissions: 830.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
// 画图可以理顺思路
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* root = node;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            node->next = l2;
            return root->next;
        }
        if (l2 == NULL) {
            node->next = l1;
            return root->next;
        }
        if (l1->val <= l2->val) {
            node->next = l1;
            l1 = l1->next;
        } else {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    return root->next;
}
