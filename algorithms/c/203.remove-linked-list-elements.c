/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (33.54%)
 * Total Accepted:    153.4K
 * Total Submissions: 457.3K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (!head)
        return NULL;
    struct ListNode* node = head;
    struct ListNode* pre = head;
    while (node) {
        if (node->val == val) {
            struct ListNode* temp = node;
            node = node->next;
            // 假如删除了头节点，那么头节点后移
            if (temp == head) {
                head = node;
                pre = head;
            }
        } else {
            pre = node;
            node = node->next;
        }
    }
    return head;
}
