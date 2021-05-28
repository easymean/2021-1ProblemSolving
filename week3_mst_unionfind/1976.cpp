#include <stdio.h>

using namespace std;

const int MAX = 200;
int n, m;
int parent[MAX + 1];
int find(int x)
{
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y)
  {
    parent[y] = x;
  }
}
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (tmp == 1)
      {
        merge(i, j);
      }
    }
  }
  int prev = 0;
  for (int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (i > 0)
    {
      if (find(tmp) != find(prev))
      {
        return !printf("NO");
      }
    }
    prev = tmp;
  }
  printf("YES");
  return 0;
}