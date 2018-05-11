/*
 * [502] IPO
 *
 * https://leetcode.com/problems/ipo/description/
 *
 * algorithms
 * Hard (36.32%)
 * Total Accepted:    7.3K
 * Total Submissions: 20.1K
 * Testcase Example:  '2\n0\n[1,2,3]\n[0,1,1]'
 *
 * 
 * Suppose LeetCode will start its IPO soon. In order to sell a good price of
 * its shares to Venture Capital, LeetCode would like to work on some projects
 * to increase its capital before the IPO. Since it has limited resources, it
 * can only finish at most k distinct projects before the IPO. Help LeetCode
 * design the best way to maximize its total capital after finishing at most k
 * distinct projects. 
 * 
 * 
 * 
 * You are given several projects. For each project i, it has a pure profit Pi
 * and a minimum capital of Ci is needed to start the corresponding project.
 * Initially, you have W capital. When you finish a project, you will obtain
 * its pure profit and the profit will be added to your total capital.
 * 
 * 
 * 
 * To sum up, pick a list of at most k distinct projects from given projects to
 * maximize your final capital, and output your final maximized capital.
 * 
 * 
 * Example 1:
 * 
 * Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
 * 
 * Output: 4
 * 
 * Explanation: Since your initial capital is 0, you can only start the project
 * indexed 0.
 * ⁠            After finishing it you will obtain profit 1 and your capital
 * becomes 1.
 * ⁠            With capital 1, you can either start the project indexed 1 or
 * the project indexed 2.
 * ⁠            Since you can choose at most 2 projects, you need to finish the
 * project indexed 2 to get the maximum capital.
 * ⁠            Therefore, output the final maximized capital, which is 0 + 1 +
 * 3 = 4.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume all numbers in the input are non-negative integers.
 * The length of Profits array and Capital array will not exceed 50,000.
 * The answer is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */

typedef struct heap_s {
    int capacity;
    int size;
    // arr[size][0] value of profit
    // arr[size][1] value of capital
    int** arr;
} heap_t;

heap_t* init(int);
void insert(heap_t*, int, int);
int* top(heap_t*);
void pop(heap_t*);
bool empty(heap_t*);

// undoable list sorted by Capital asc
int undocmp(void** a, void** b) { return (*(int**)a)[1] - (*(int**)b)[1]; }

int findMaximizedCapital(int k, int W, int* Profits, int ProfitsSize, int* Capital, int CapitalSize)
{
    heap_t* doalbe = init(ProfitsSize);
    int** undoable = NULL;
    int i, undoableSize = 0;
    for (i = 0; i < ProfitsSize; i++) {
        if (Profits[i] <= 0)
            continue;
        if (Capital[i] <= W) {
            // printf("[%d %d]", Profits[i], Capital[i]);
            insert(doalbe, Profits[i], Capital[i]);
        } else {
            undoable = (int**)realloc(undoable, sizeof(int*) * (++undoableSize));
            int* item = (int*)malloc(sizeof(int) * 2);
            item[0] = Profits[i], item[1] = Capital[i];
            undoable[undoableSize - 1] = item;
        }
    }
    qsort(undoable, undoableSize, sizeof(int*), undocmp);
    i = 0;
    while (!empty(doalbe) && k--) {
        // printf("[%d,%d,%d] ", W, top(doalbe)[0], W + top(doalbe)[0]);
        W += top(doalbe)[0];
        pop(doalbe);
        while (i < undoableSize) {
            // move undoable projects to doable heap
            if (W >= undoable[i][1]) {
                insert(doalbe, undoable[i][0], undoable[i][1]);
                i++;
            } else
                break;
        }
    }
    return W;
}

heap_t* init(int max)
{
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = max;
    heap->size = 0;
    heap->arr = (int**)malloc(sizeof(int*) * (max + 1));
    return heap;
}

bool empty(heap_t* heap) { return heap->size == 0; }
int* top(heap_t* heap) { return heap->arr[1]; }

// if a < b
bool cmp(int* a, int* b) { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; }

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
    for (int i = heap->size; i > 1 && cmp(heap->arr[i], heap->arr[i / 2]); i /= 2)
        swap(heap->arr, i, i / 2);
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