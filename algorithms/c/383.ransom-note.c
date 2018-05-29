/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (47.91%)
 * Total Accepted:    81K
 * Total Submissions: 169K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
bool canConstruct(char* ransomNote, char* magazine)
{
    int letters[26] = { 0 };
    while (*magazine)
        letters[(*magazine++) - 'a']++;
    while (*ransomNote) {
        if (letters[(*ransomNote) - 'a'] == 0)
            return false;
        letters[(*ransomNote++) - 'a']--;
    }
    return true;
}
