#include <stdio.h>
#define DIV 10007

using namespace std;

int dp[1001][1001];
int main(void)
{
  dp[1][0] = 1;
  dp[1][1] = 1;
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
      {
        dp[i][j] = 1;
      }
      else
      {
        //dp[i-1][j]가 크지 않으므로 안나눠줘도 됨
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % DIV;
      }
    }
  }

  printf("%d\n", dp[n][k]);

  return 0;
}