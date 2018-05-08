/*
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (25.80%)
 * Total Accepted:    31.6K
 * Total Submissions: 122.4K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 * 
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 * 
 * 
 */
struct Node {
    char c;
    struct Node* next;
};

char* removeKdigits(char* num, int k)
{
    int len = strlen(num);
    if (k >= len || len == 0)
        return "0";
    int j = len - k, i;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->c = *num;
    head->next = NULL;
    for (i = 1; i < len && k > 0; i++) {
        if (head && head->c > num[i]) {
            while (head && head->c > num[i] && k > 0) {
                struct Node* temp = head;
                head = head->next;
                free(temp);
                k--;
            }
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->c = num[i];
            node->next = head;
            head = node;
        } else {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->c = num[i];
            node->next = head;
            head = node;
        }
    }
    while (i < len) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->c = num[i++];
        node->next = head;
        head = node;
    }
    while (k > 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        k--;
    }

    num[j] = '\0';
    while (head) {
        struct Node* temp = head;
        head = head->next;
        num[--j] = temp->c;
        free(temp);
    }

    while (*num == '0')
        num++;

    return *num == '\0' ? "0" : num;
}
