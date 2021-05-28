//냅색

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100000;
int dp[100 + 1][MAX + 1];
vector<pair<int, int>> bag;
int n, k, w, v;
int main(void)
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &w, &v);
    bag.push_back(make_pair(w, v));
  }

  for (int i = 0; i < n; i++)
  {
    w = bag[i].first, v = bag[i].second;
    for (int j = 1; j <= k; j++)
    {
      if (j >= w)
      {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v);
      }
      else
      {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  printf("%d", dp[n][k]);
  return 0;
}