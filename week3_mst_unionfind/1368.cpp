/*
가상의 노드를 만들어서 MST를 만드는 문제
*/
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 300;
int n;
int p[MAX + 1];
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
  //0번째 노드를 새로 추가한다.
  for (int i = 1; i <= n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    vs.push_back({0, i, tmp});
    p[i] = i;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (i >= j)
        continue;

      vs.push_back({i, j, tmp});
      //printf("%d with %d : %d\n", i, j, tmp);
    }
  }

  sort(vs.begin(), vs.end());
  int result = 0;
  for (int i = 0; i < vs.size(); i++)
  {
    int u = vs[i].u, v = vs[i].v, c = vs[i].c;
    if (find(u) != find(v))
    {
      merge(u, v);
      result += c;
    }
  }

  printf("%d", result);
  return 0;
}