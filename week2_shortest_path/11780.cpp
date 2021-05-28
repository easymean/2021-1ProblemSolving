#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100 + 1;
const long long INF = 10000000000;
int n, m;
long long arr[MAX][MAX];
int path[MAX][MAX];

vector<int> tmp;
void findPath(int from, int to)
{
  int prev = path[from][to];
  if (from == prev)
  {
    tmp.push_back(from);
    return;
  }

  findPath(from, prev);
  findPath(prev, to);
}
int main(void)
{
  scanf("%d%d", &n, &m);

  //경로 초기화
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      arr[i][j] = INF;
      path[i][j] = i;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (arr[a][b] > c)
    {
      arr[a][b] = c;
    }
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i == j || j == k || k == i)
          continue;

        if (arr[i][j] > arr[i][k] + arr[k][j])
        {
          arr[i][j] = arr[i][k] + arr[k][j];
          path[i][j] = k;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == INF)
      {
        printf("0 ");
      }
      else
      {
        printf("%lld ", arr[i][j]);
      }
    }
    printf("\n");
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == INF)
      {
        printf("0");
      }
      else
      {
        tmp.clear();
        findPath(i, j);
        tmp.push_back(j);

        int sze = tmp.size();

        printf("%d ", sze);
        for (int k = 0; k < sze; k++)
        {
          printf("%d ", tmp[k]);
        }
      }
      printf("\n");
    }
  }
  return 0;
}