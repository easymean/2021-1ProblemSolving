//역추적
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAX = 1010;
int n, m;
char a[MAX];
char b[MAX];
int dp[MAX][MAX];

int findLCS(int idx1, int idx2)
{
  if (idx1 == n || idx2 == m)
    return dp[idx1][idx2] = 0;

  int &res = dp[idx1][idx2];
  if (res != -1)
    return res;

  res = max(findLCS(idx1 + 1, idx2), findLCS(idx1, idx2 + 1));
  if (a[idx1] == b[idx2])
    res = max(res, 1 + findLCS(idx1 + 1, idx2 + 1));
  return res;
}

void track(int idx1, int idx2)
{
  if (idx1 == n || idx2 == m)
    return;

  int res = dp[idx1][idx2];

  if (res == dp[idx1 + 1][idx2])
  {
    track(idx1 + 1, idx2);
    return;
  }

  if (res == dp[idx1][idx2 + 1])
  {
    track(idx1, idx2 + 1);
    return;
  }

  if (a[idx1] == b[idx2] && res == 1 + dp[idx1 + 1][idx2 + 1])
  {
    putchar(a[idx1]);
    track(idx1 + 1, idx2 + 1);
    return;
  }
}

int main(void)
{
  memset(dp, -1, sizeof(dp));
  scanf("%s%s", a, b);
  n = strlen(a), m = strlen(b);
  printf("%d\n", findLCS(0, 0));
  track(0, 0);
  return 0;
}