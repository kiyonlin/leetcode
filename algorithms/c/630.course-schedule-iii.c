/*
 * [630] Course Schedule III
 *
 * https://leetcode.com/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (29.46%)
 * Total Accepted:    6.1K
 * Total Submissions: 20.6K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * 
 * There are n different online courses numbered from 1 to n. Each course has
 * some duration(course length)  t and closed on dth day. A course should be
 * taken continuously for t days and must be finished before or on the dth day.
 * You will start at the 1st day.
 * 
 * 
 * 
 * Given n online courses represented by pairs (t,d), your task is to find the
 * maximal number of courses that can be taken.
 * 
 * 
 * 
 * Example:
 * 
 * Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * Output: 3
 * Explanation: 
 * There're totally 4 courses, but you can take 3 courses at most:
 * First, take the 1st course, it costs 100 days so you will finish it on the
 * 100th day, and ready to take the next course on the 101st day.
 * Second, take the 3rd course, it costs 1000 days so you will finish it on the
 * 1100th day, and ready to take the next course on the 1101st day. 
 * Third, take the 2nd course, it costs 200 days so you will finish it on the
 * 1300th day. 
 * The 4th course cannot be taken now, since you will finish it on the 3300th
 * day, which exceeds the closed date.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The integer 1 
 * You can't take two courses simultaneously.
 * 
 * 
 */

typedef struct heap_s {
    int capacity;
    int size;
    int* arr;
} heap_t;

heap_t* init(int);
void insert(heap_t*, int);
int top(heap_t*);
void pop(heap_t*);

// course list sorted by deadline asc
int deadlinecmp(void** a, void** b) { return (*(int**)a)[1] - (*(int**)b)[1]; }

int scheduleCourse(int** courses, int coursesRowSize, int* coursesColSizes)
{
    heap_t* heap = init(coursesRowSize);
    qsort(courses, coursesRowSize, sizeof(int*), deadlinecmp);
    int t = 0;
    for (int i = 0; i < coursesRowSize; i++) {
        // learn course i
        t += courses[i][0];
        insert(heap, courses[i][0]);
        // when time is over deadline
        if (t > courses[i][1]) {
            // remove the most long duration course
            t -= top(heap);
            pop(heap);
        }
    }

    return heap->size;
}

heap_t* init(int max)
{
    heap_t* heap = (heap_t*)malloc(sizeof(heap_t));
    heap->capacity = max;
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int) * (max + 1));
    return heap;
}

int top(heap_t* heap) { return heap->arr[1]; }

void swap(int* a, int i, int j)
{
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
}

void insert(heap_t* heap, int val)
{
    heap->arr[++heap->size] = val;
    for (int i = heap->size; i > 1 && heap->arr[i] > heap->arr[i / 2]; i /= 2)
        swap(heap->arr, i, i / 2);
}
void pop(heap_t* heap)
{
    heap->arr[1] = heap->arr[heap->size--];
    for (int i = 1; i * 2 <= heap->size;) {
        // find smaller child to compare with the current node
        int child = heap->arr[i * 2] > heap->arr[i * 2 + 1] ? i * 2 : i * 2 + 1;
        if (heap->arr[child] > heap->arr[i]) {
            // swap if child is smaller
            swap(heap->arr, child, i);
            i = child;
        } else
            break;
    }
}