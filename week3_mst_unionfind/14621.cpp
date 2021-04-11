#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct s
{
  int u, v, c;
};
bool cmp(const s &t1, const s &t2)
{
  return t1.c < t2.c;
}
vector<s> vs;

const int MAX = 1000 + 1;
int parent[MAX];
char flag[MAX];
int n, m;
int find(int x)
{
  if (x == parent[x])
  {
    return x;
  }

  return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  int px = find(x);
  int py = find(y);
  if (px != py)
  {
    parent[py] = px;
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> flag[i];
  }

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    vs.push_back({a, b, c});
  }

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }

  sort(vs.begin(), vs.end(), cmp);

  int answer = 0;
  for (auto a : vs)
  {
    int v1 = a.u, v2 = a.v, cost = a.c;
    if (find(v1) == find(v2) || flag[v1] == flag[v2])
    {
      continue;
    }
    merge(v1, v2);
    answer += cost;
  }
  bool flag = true;
  int pp = find(1);
  for (int i = 2; i <= n; i++)
  {
    if (find(i) != pp)
    {
      flag = false;
      break;
    }
  }

  if (!flag)
    cout << "-1";
  else
    cout << answer;
  return 0;
}