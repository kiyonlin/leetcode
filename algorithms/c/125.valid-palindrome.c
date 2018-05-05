/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.19%)
 * Total Accepted:    226.5K
 * Total Submissions: 832.9K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
bool isPalindrome(char* s)
{
    int head = 0, rear = strlen(s) - 1;
    while (head < rear) {
        if (!isalnum(s[head])) {
            head++;
            continue;
        }
        if (!isalnum(s[rear])) {
            rear--;
            continue;
        }
        if (tolower(s[head]) != tolower(s[rear]))
            return false;
        head++, rear--;
    }
    return true;
}
