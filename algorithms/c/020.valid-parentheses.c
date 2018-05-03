/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.02%)
 * Total Accepted:    331.5K
 * Total Submissions: 973.3K
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
// 第二种解法，char数组模拟堆栈
bool checkPair(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

bool isValid(char* s)
{
    int len = strlen(s);
    if (len % 2)
        return false;
    // 模拟堆栈
    char* stack = malloc(sizeof(char) * (len + 1));
    // 调整到前一处内存，为循环做准备
    stack--;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            *(++stack) = s[i];
        } else {
            if (!checkPair(*stack, s[i]))
                return false;
            stack--;
        }
    }
    if (*stack == '(' || *stack == '[' || *stack == '{')
        return false;

    return true;
}

// 第一种解法
// 找出匹配的括号并标记为已经查找过
// bool checkPair(char pair, int start, char* s)
// {
//     int len = strlen(s);
//     while (start < len) {
//         if (s[start] == pair) {
//             s[start] = '_';
//             return true;
//         }
//         // 括号都是成对出现
//         start += 2;
//     }
//     return false;
// }

// bool isValid(char* s)
// {
//     int len = strlen(s);
//     if (len % 2)
//         return false;
//     for (int i = 0; i < len; i++) {
//         if (s[i] == '_')
//             continue;
//         if (s[i] == '(' && !checkPair(')', i + 1, s)) {
//             return false;
//         }
//         if (s[i] == '[' && !checkPair(']', i + 1, s)) {
//             return false;
//         }
//         if (s[i] == '{' && !checkPair('}', i + 1, s)) {
//             return false;
//         }
//         // 其他情况均非法
//         if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//             return false;
//     }
//     return true;
// }
