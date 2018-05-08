/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.32%)
 * Total Accepted:    108.4K
 * Total Submissions: 275.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * 
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 */
int isVowel(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
char* reverseVowels(char* s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        if (!isVowel(s[left])) {
            left++;
            continue;
        }
        if (!isVowel(s[right])) {
            right--;
            continue;
        }
        if (s[left] != s[right]) {
            s[left] = s[left] ^ s[right];
            s[right] = s[left] ^ s[right];
            s[left] = s[left] ^ s[right];
        }
        left++, right--;
    }
    return s;
}
