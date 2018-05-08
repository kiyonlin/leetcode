/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (60.44%)
 * Total Accepted:    245.4K
 * Total Submissions: 405.9K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
inline void swap(char* a, char* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
char* reverseString(char* s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            s[left] = s[left] ^ s[right];
            s[right] = s[left] ^ s[right];
            s[left] = s[left] ^ s[right];
        }
        left++, right--;
    }
    return s;
}
