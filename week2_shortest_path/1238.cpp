#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 900000000;

bool chk[MAX];
int dis[MAX];
int rdis[MAX];

int n, m, dest;
int s, e, d;

vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>> pq;
int main(void)
{
  scanf("%d%d%d", &n, &m, &dest);

  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &s, &e, &d);
    adj[s].push_back(make_pair(e, d));
  }

  //목적지에서 각 마을까지
  for (int j = 1; j <= n; j++)
  {
    rdis[j] = INF;
    chk[j] = false;
  }
  rdis[dest] = 0;

  pq.push({0, dest});

  while (!pq.empty())
  {
    int curs = pq.top().second;
    pq.pop();
    if (chk[curs])
      continue;
    chk[curs] = true;

    for (auto &a : adj[curs])
    {
      int nexts = a.first, nextd = a.second;
      rdis[nexts] = min(rdis[nexts], rdis[curs] + nextd);
      pq.push(make_pair(-rdis[nexts], nexts));
    }
  }

  int result = -1;
  for (int i = 1; i <= n; i++)
  {
    if (i == dest)
      continue;
    for (int j = 1; j <= n; j++)
    {
      dis[j] = INF;
      chk[j] = false;
    }
    dis[i] = 0;

    pq.push({0, i});

    while (!pq.empty())
    {
      int curs = pq.top().second;
      pq.pop();
      if (chk[curs])
        continue;
      chk[curs] = true;

      for (auto &a : adj[curs])
      {
        int nexts = a.first, nextd = a.second;
        dis[nexts] = min(dis[nexts], dis[curs] + nextd);
        pq.push(make_pair(-dis[nexts], nexts));
      }
    }

    result = max(result, dis[dest] + rdis[i]);
  }
  printf("%d\n", result);
  return 0;
}