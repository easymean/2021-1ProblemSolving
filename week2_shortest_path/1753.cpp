//min heap 사용
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 20000 + 1
#define INF 1000000000

using namespace std;

vector<pair<int, int>> vec[MAX];
priority_queue<pair<int, int>> pq;
int v, e, start;
bool chk[MAX];
int dist[MAX];
int main(void)
{
  scanf("%d%d%d", &v, &e, &start);
  int fr, to, di;
  for (int i = 0; i < e; i++)
  {
    scanf("%d%d%d", &fr, &to, &di);
    vec[fr].push_back(make_pair(di, to));
  }

  for (int i = 1; i <= v; i++)
  {
    dist[i] = INF;
  }

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty())
  {
    int curNode = pq.top().second;
    pq.pop();
    if (chk[curNode])
      continue;

    chk[curNode] = true;
    for (auto a : vec[curNode])
    {
      dist[a.second] = min(dist[a.second], dist[curNode] + a.first);
      pq.push({-dist[a.second], a.second});
    }
  }

  for (int i = 1; i <= v; i++)
  {

    if (dist[i] == INF)
    {
      printf("INF\n");
    }
    else
    {
      printf("%d\n", dist[i]);
    }
  }
  return 0;
}