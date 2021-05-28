#include <stdio.h>

using namespace std;

const int MAX = 1000000 + 1;
int n, m;
int parent[MAX];

int findParent(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = findParent(parent[x]);
}

void unionSet(int x, int y)
{
  int px = findParent(x);
  int py = findParent(y);
  if (px != py)
    parent[py] = px;
}
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }
  for (int i = 0; i < m; i++)
  {
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    if (s == 0)
    {
      if (a < b)
      {
        unionSet(a, b);
      }
      else if (a > b)
      {
        unionSet(b, a);
      }
    }
    else
    {
      if (findParent(a) == findParent(b))
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
  return 0;
}