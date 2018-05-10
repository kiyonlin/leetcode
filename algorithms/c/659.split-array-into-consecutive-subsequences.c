/*
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (37.00%)
 * Total Accepted:    8.5K
 * Total Submissions: 23.1K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * You are given an integer array sorted in ascending order (may contain
 * duplicates), you need to split them into several subsequences, where each
 * subsequences consist of at least 3 consecutive integers. Return whether you
 * can make such a split.
 * 
 * Example 1:
 * 
 * Input: [1,2,3,3,4,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3
 * 3, 4, 5
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,3,4,4,5,5]
 * Output: True
 * Explanation:
 * You can split them into two consecutive subsequences : 
 * 1, 2, 3, 4, 5
 * 3, 4, 5
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [1,2,3,4,4,5]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input is in range of [1, 10000]
 * 
 * 
 */
// 堆（数据结构）https://zh.wikipedia.org/wiki/%E5%A0%86_(%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84)

typedef struct heap_s {
    int capacity;
    int size;
    // arr[size][0] max value of sequence
    // arr[size][1] length of sequence
    int** arr;
} heap_t;

heap_t* init(int);
void insert(heap_t*, int, int);
int* top(heap_t*);
void pop(heap_t*);
bool empty(heap_t*);

bool isPossible(int* nums, int numsSize)
{
    heap_t* heap = init(numsSize);
    for (int i = 0; i < numsSize; i++) {
        // can't put value to the sequence any more
        while (!empty(heap) && nums[i] - top(heap)[0] > 1) {
            // find invalid sequence, return false
            if (top(heap)[1] < 3)
                return false;
            pop(heap);
        }
        if (empty(heap) || nums[i] == top(heap)[0]) {
            // add a new sequence
            insert(heap, nums[i], 1);
        } else {
            // update the old sequence's value and length
            int length = top(heap)[1] + 1;
            pop(heap);
            insert(heap, nums[i], length);
        }
    }
    while (!empty(heap)) {
        // find invalid sequence, return false
        if (top(heap)[1] < 3)
            return false;
        pop(heap);
    }
    return true;
}

heap_t* init(int max)
{
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = max;
    heap->size = 0;
    heap->arr = (int**)malloc(sizeof(int*) * (max + 1));
    return heap;
}

// if a < b
bool cmp(int* a, int* b)
{
    return a[0] == b[0] ? b[1] > a[1] : b[0] > a[0];
}

void swap(int** a, int i, int j)
{
    int* tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void insert(heap_t* heap, int val, int length)
{
    int* node = (int*)malloc(sizeof(int) * 2);
    node[0] = val, node[1] = length;
    heap->arr[++heap->size] = node;
    for (int i = heap->size; i > 1 && cmp(heap->arr[i], heap->arr[i / 2]); i /= 2) {
        swap(heap->arr, i, i / 2);
    }
}
int* top(heap_t* heap)
{
    return heap->arr[1];
}
void pop(heap_t* heap)
{
    heap->arr[1] = heap->arr[heap->size--];
    for (int i = 1; i * 2 <= heap->size;) {
        // find smaller child to compare with the current node
        int child = cmp(heap->arr[i * 2], heap->arr[i * 2 + 1]) ? i * 2 : i * 2 + 1;
        if (cmp(heap->arr[child], heap->arr[i])) {
            // swap if child is smaller
            swap(heap->arr, child, i);
            i = child;
        } else
            break;
    }
}
bool empty(heap_t* heap)
{
    return heap->size == 0;
}
