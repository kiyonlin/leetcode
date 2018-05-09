/*
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (56.42%)
 * Total Accepted:    45.3K
 * Total Submissions: 80.3K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * 
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct LinkedNode {
    int h;
    int k;
    struct LinkedNode* next;
} list;

// 先按h从大到小，后按k从小到大排序
int cmp(void* aa, void* bb)
{
    int* a = *(int**)aa;
    int* b = *(int**)bb;
    if (a[0] == b[0])
        return a[1] - b[1];
    else
        return b[0] - a[0];
}
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize)
{
    *returnSize = peopleRowSize;
    qsort(people, peopleRowSize, sizeof(int*), cmp);

    list* head = (list*)malloc(sizeof(list));
    head->next = NULL;

    // 高度从大到小，位置从小到大开始排序
    int i, j;
    for (i = 0; i < peopleRowSize; i++) {
        list* cur = head;
        // 根据位置后移动指针
        for (j = 0; j < people[i][1]; j++) {
            cur = cur->next;
        }
        list* node = (list*)malloc(sizeof(list));
        node->h = people[i][0];
        node->k = people[i][1];
        node->next = cur->next;
        cur->next = node;
    }

    int** result = (int**)malloc(sizeof(int*) * (*returnSize));
    for (i = 0; i < peopleRowSize; i++) {
        result[i] = (int*)malloc(sizeof(int) * 2);
        result[i][0] = head->next->h;
        result[i][1] = head->next->k;
        head = head->next;
    }

    return result;
}
