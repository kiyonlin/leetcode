/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (25.36%)
 * Total Accepted:    78.6K
 * Total Submissions: 310K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */
int candy(int* ratings, int ratingsSize)
{
    if (ratingsSize < 2)
        return ratingsSize;

    int* count = (int*)malloc(sizeof(int) * ratingsSize);
    for (int i = 0; i < ratingsSize; i++) {
        count[i] = 1;
    }
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1])
            count[i] = count[i - 1] + 1;
    }
    int result = count[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && count[i] < count[i + 1] + 1)
            count[i] = count[i + 1] + 1;
        result += count[i];
    }

    return result;
}
