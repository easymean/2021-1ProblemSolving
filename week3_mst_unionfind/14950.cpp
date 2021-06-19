/* 
1번 노드에서 무조건 시작해야할것 같지만 
사실 mst면 무슨노드에서 시작하든 상관없다. 
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int parent[MAX + 1];

struct s
{
  int u, v, c;
  bool operator<(const s &cmp) const
  {
    return c < cmp.c;
  }
};

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

vector<s> vs;
int main(void)
{
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vs.push_back({a, b, c});
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  sort(vs.begin(), vs.end());

  int result = 0, cnt = 0;
  for (int i = 0; i < m; i++)
  {
    int u = vs[i].u, c = vs[i].c, v = vs[i].v;

    if (find(u) != find(v))
    {
      merge(u, v);
      result += c + (cnt * t);
      cnt++;
    }
  }

  printf("%d", result);

  return 0;
}