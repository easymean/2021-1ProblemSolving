#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 100000000
#define CITY 1001

using namespace std;

struct s
{
  int to, dist;
};

vector<s> v[CITY];
int n, m, start, last;
bool chk[CITY];
int dist[CITY];
int main(void)
{

  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++)
  {
    int from, to, dist;
    scanf("%d%d%d", &from, &to, &dist);
    v[from].push_back({to, dist});
  }
  scanf("%d%d", &start, &last);

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
  }
  dist[start] = 0;

  int sum = 0;

  while (1)
  {
    int minIdx = 0;
    int minDist = INF;

    //가장 작은 길이를 갖는 정점x를 찾기
    for (int i = 1; i <= n; i++)
    {
      if (chk[i])
        continue;

      if (dist[i] < minDist)
      {
        minDist = dist[i];
        minIdx = i;
      }
    }

    int cur = minIdx;
    //x와 인접한 접점들의 최소 거리 업데이트
    for (auto a : v[cur])
    {
      if (chk[a.to])
        continue;

      dist[a.to] = min(dist[a.to], a.dist + dist[cur]);
    }

    chk[cur] = true;

    if (cur == last)
    {
      break;
    }
  }

  printf("%d\n", dist[last]);
  return 0;
}