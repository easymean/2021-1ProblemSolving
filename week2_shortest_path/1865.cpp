#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 500 + 1;
const int INF = 10000000;

int t, n, m, w;
int s, e, d;

int dis[MAX];

int main(void)
{
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d%d", &n, &m, &w);
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d", &s, &e, &d);
      adj[s].push_back(make_pair(e, d));
      adj[e].push_back(make_pair(s, d));
    }

    for (int i = 0; i < w; i++)
    {
      scanf("%d%d%d", &s, &e, &d);
      adj[s].push_back(make_pair(e, -d));
    }

    dis[1] = 0;
    for (int i = 2; i <= n; i++)
    {
      dis[i] = INF;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        for (auto &a : adj[j])
        {
          int next = a.first;
          int nextd = a.second;

          if (dis[next] > dis[j] + nextd)
          {
            dis[next] = dis[j] + nextd;
            if (i == n)
            {
              flag = true;
            }
          }
        }
      }
    }

    if (flag)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}