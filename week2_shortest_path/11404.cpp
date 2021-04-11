#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 10000000 + 1;

int n, m;
int arr[101][101];
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      arr[i][j] = MAX;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    arr[from][to] = min(cost, arr[from][to]);
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i == j || k == i || j == k)
          continue;
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == MAX)
      {
        printf("0 ");
      }
      else
      {
        printf("%d ", arr[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}