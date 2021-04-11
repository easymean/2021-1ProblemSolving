#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, m, src, dst;
const int MAX = 1000 + 1;
const long long INF = 10000000000;
priority_queue<pair<long long, int>> pq;
vector<pair<long long, int>> v[MAX];

long long dist[MAX];
bool chk[MAX];
int path[MAX];
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    v[a].push_back(make_pair(c, b));
  }

  scanf("%d%d", &src, &dst);

  for (int i = 1; i <= n; i++)
  {
    dist[i] = INF;
    path[i] = i;
  }

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty())
  {
    int curNode = pq.top().second;
    pq.pop();

    if (chk[curNode])
      continue;
    chk[curNode] = true;

    for (auto a : v[curNode])
    {
      if (dist[a.second] > dist[curNode] + a.first)
      {
        dist[a.second] = dist[curNode] + a.first;
        pq.push(make_pair(-dist[a.second], a.second));
        path[a.second] = curNode;
      }
    }
  }
  printf("%lld\n", dist[dst]);

  vector<int> answer;
  int x = dst;
  while (x != path[x])
  {
    answer.push_back(x);
    x = path[x];
  }
  answer.push_back(x);

  int sze = answer.size();
  printf("%d\n", sze);
  for (int i = sze - 1; i > -1; i--)
  {
    printf("%d ", answer[i]);
  }
  return 0;
}