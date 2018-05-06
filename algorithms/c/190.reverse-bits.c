/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.38%)
 * Total Accepted:    133.8K
 * Total Submissions: 455.6K
 * Testcase Example:  '    43261596 (00000010100101000001111010011100)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Example:
 * 
 * 
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as
 * 00000010100101000001111010011100, 
 * return 964176192 represented in binary as
 * 00111001011110000010100101000000.
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 */
uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    int count = 32;
    while (n) {
        result = (result << 1) | (n & 1);
        n >>= 1;
        count--;
    }
    return result <<= count;
}
