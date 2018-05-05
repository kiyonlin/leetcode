/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (31.43%)
 * Total Accepted:    187K
 * Total Submissions: 595K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
typedef struct {
    int top;
    int min;
    int* val;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize)
{
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    if (!stack)
        return NULL;
    stack->top = 0;
    stack->min = INT_MAX;
    stack->val = (int*)malloc(sizeof(int) * maxSize);
    return stack;
}

void minStackPush(MinStack* obj, int x)
{
    if (x < obj->min)
        obj->min = x;
    return obj->val[obj->top++] = x;
}

void minStackPop(MinStack* obj)
{
    obj->top--;
    // 删除了最小值，及时更新
    if (obj->val[obj->top] == obj->min) {
        obj->min = INT_MAX;
        for (int i = 0; i < obj->top; i++) {
            if (obj->val[i] < obj->min) {
                obj->min = obj->val[i];
            }
        }
    }
}

int minStackTop(MinStack* obj)
{
    return obj->val[obj->top - 1];
}

int minStackGetMin(MinStack* obj)
{
    return obj->min;
}

void minStackFree(MinStack* obj)
{
    free(obj->val);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
