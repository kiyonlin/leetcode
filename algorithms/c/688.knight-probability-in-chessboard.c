/*
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (40.24%)
 * Total Accepted:    7.4K
 * Total Submissions: 18.4K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * 
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and
 * attempts to make exactly K moves.  The rows and columns are 0 indexed, so
 * the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * 
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below.  Each
 * move is two squares in a cardinal direction, then one square in an
 * orthogonal direction.
 * 
 * 
 * 
 * 
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * 
 * 
 * The knight continues moving until it has made exactly K moves or has moved
 * off the chessboard.  Return the probability that the knight remains on the
 * board after it has stopped moving.
 * 
 * 
 * Example:
 * 
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * 
 * Note:
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 * 
 */
double knightProbability(int N, int K, int sr, int sc)
{
    double dp[N][N];
    memset(dp, 0, sizeof(dp));
    dp[sr][sc] = 1.0;
    int dr[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
    int dc[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
    double dp2[N][N];
    while (K--) {
        memset(dp2, 0, sizeof(dp2));
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                for (int k = 0; k < 8; k++) {
                    int cr = r + dr[k];
                    int cc = c + dc[k];
                    if (cr >= 0 && cr < N && cc >= 0 && cc < N)
                        dp2[cr][cc] += dp[r][c] / 8.0;
                }
        memcpy(dp, dp2, sizeof(dp));
    }
    double result = 0.0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result += dp[i][j];

    return result;
}
