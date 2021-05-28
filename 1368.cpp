#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 300;
int n;
int w[MAX + 1];
int p[MAX + 1];
int visited[MAX + 1];
struct s
{
  int u, v, c;
  bool operator<(const s &cmp) const
  {
    return c < cmp.c;
  }
};
vector<s> vs;

int find(int x)
{
  if (x == p[x])
    return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y)
  {
    p[y] = x;
  }
}

int main(void)
{
  scanf("%d", &n);
  int start = 0, minValue = 100000 + 1;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &w[i]);
    if (w[i] < minValue)
    {
      minValue = w[i];
      start = i;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (i < j)
      {
        vs.push_back({i, j, tmp});
      }
      else
      {
        vs.push_back({j, i, tmp});
      }
    }
  }

  sort(vs.begin(), vs.end());
  int result = 0;
  for (int i = 0; i < vs.size(); i++)
  {
    int u = vs[i].u, v = vs[i].v, c = vs[i].c;
    if (!visited[u] && !visited[v])
    {
    }
  }
  return 0;
}