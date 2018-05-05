/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.86%)
 * Total Accepted:    190.3K
 * Total Submissions: 616.5K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 将A首尾相连，从B出发，发现环则可以找出相交点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (!headA)
        return NULL;
    struct ListNode* rearA = headA;
    while (rearA && rearA->next)
        rearA = rearA->next;
    // A设为环
    rearA->next = headA;

    struct ListNode *slow = headB, *fast = headB;
    short flag = 0;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = 1;
            break;
        }
    }
    struct ListNode* result = NULL;
    if (flag) {
        result = headB;
        while (result != slow) {
            result = result->next;
            slow = slow->next;
        }
    }
    //重置A链表
    rearA->next = NULL;
    return result;
}
