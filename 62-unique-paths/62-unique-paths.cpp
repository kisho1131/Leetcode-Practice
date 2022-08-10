class Solution {
public:
int uniquePaths(int m, int n) {
    int memo[101][101];
    memset(memo, 0,sizeof(memo));
    return uniquePathsHelper(m - 1, n - 1, memo);
  }
  
      private:
        int uniquePathsHelper(int m, int n, int memo[101][101]) {
        if (m < 0 || n < 0) {
          return 0;
        } else if (m == 0 || n == 0) {
          return 1;
        } else if (memo[n][m] > 0) {
          return memo[n][m];
        } else {
          memo[n][m] = uniquePathsHelper(m - 1, n, memo) + uniquePathsHelper(m, n - 1, memo);
          return memo[n][m];
        }
      }
};