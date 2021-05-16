#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 2;
int dp[MAX][MAX];
char s[MAX];
char t[MAX];

int main(void)
{
  scanf("%s %s", s + 1, t + 1);
  int lens = strlen(s + 1), lent = strlen(t + 1);
  for (int i = 1; i <= lens; i++)
  {
    for (int j = 1; j <= lent; j++)
    {
      if (s[i] == t[j])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  printf("%d", dp[lens][lent]);
  return 0;
}