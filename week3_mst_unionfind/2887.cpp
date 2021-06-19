/*
  데이터 제한이 128MB여서 어려웠던 문제
  주어진 조건이 10^5 이기 때문에 
  N개 노드 사이의 모든 COST를 벡터에 저장한다면
  용량이 초과한다.
  따라서 X, Y, Z를 기준으로 정렬 후 3(N-1)개의 COST만
  저장한다.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
const int MAX = 100000;
struct s
{
  int u, v, c;
  bool operator<(const s &cmp)
      const
  {
    return c < cmp.c;
  }
};

struct node
{
  int x, y, z, num;
};

bool cmpx(const node &a, const node &b)
{
  return a.x < b.x;
};

bool cmpy(const node &a, const node &b)
{
  return a.y < b.y;
};

bool cmpz(const node &a, const node &b)
{
  return a.z < b.z;
};

vector<s> vs;
vector<node> vn;
int arr[MAX][3];
int p[MAX];

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
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    vn.push_back({x, y, z, i});
  }

  sort(vn.begin(), vn.end(), cmpx);
  for (int i = 0; i < n - 1; i++)
  {
    int c = abs(vn[i].x - vn[i + 1].x);
    vs.push_back({vn[i].num, vn[i + 1].num, c});
  }
  sort(vn.begin(), vn.end(), cmpy);
  for (int i = 0; i < n - 1; i++)
  {
    int c = abs(vn[i].y - vn[i + 1].y);
    vs.push_back({vn[i].num, vn[i + 1].num, c});
  }
  sort(vn.begin(), vn.end(), cmpz);
  for (int i = 0; i < n - 1; i++)
  {
    int c = abs(vn[i].z - vn[i + 1].z);
    vs.push_back({vn[i].num, vn[i + 1].num, c});
  }

  sort(vs.begin(), vs.end());

  for (int i = 0; i < n; i++)
  {
    p[i] = i;
  }

  long long result = 0;
  for (int i = 0; i < 3 * (n - 1); i++)
  {
    int u = vs[i].u, v = vs[i].v, c = vs[i].c;
    if (find(u) != find(v))
    {
      merge(u, v);
      result += c;
    }
  }
  printf("%lld", result);
  return 0;
}