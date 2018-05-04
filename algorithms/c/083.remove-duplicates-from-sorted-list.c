/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.32%)
 * Total Accepted:    235.8K
 * Total Submissions: 584.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;
    while (cur != NULL) {
        // 当前与前一个值相等，则删除当前节点
        if (cur->val == pre->val) {
            struct ListNode* temp = cur;
            cur = cur->next;
            pre->next = cur;
            free(temp);
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}
