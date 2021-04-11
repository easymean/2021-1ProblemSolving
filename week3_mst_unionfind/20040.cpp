#include <stdio.h>

using namespace std;

const int MAX = 500000 + 1;

int n, m;
int parent[MAX];
int findP(int x)
{
  if (x == parent[x])
  {
    return x;
  }

  return parent[x] = findP(parent[x]);
}

void merge(int x, int y)
{
  int px = findP(x);
  int py = findP(y);

  if (px != py)
  {
    parent[py] = px;
  }
}

int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if (findP(a) == findP(b))
    {
      printf("%d", i + 1);
      return 0;
    }

    merge(a, b);
  }
  printf("0");
  return 0;
}