#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAX = 100000 + 1;
int parent[MAX];
struct s
{
  int e, u, c;
};
s edges[MAX];

bool cmp(const s &t1, const s &t2)
{
  if (t1.c == t2.c)
  {
    return t1.e < t2.e;
  }
  return t1.c < t2.c;
}

int n, m;

int findP(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = findP(parent[x]);
}

void merge(int x, int y)
{
  int px = findP(x);
  int py = findP(y);

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
    scanf("%d%d%d", &edges[i].e, &edges[i].u, &edges[i].c);
  }

  sort(edges, edges + m, cmp);
  int answer = 0;
  for (int i = 0; i < m; i++)
  {
    s a = edges[i];
    if (findP(a.e) == findP(a.u))
      continue;
    answer += a.c;
    merge(a.e, a.u);
  }

  printf("%d\n", answer);
  return 0;
}