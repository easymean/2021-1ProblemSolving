#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 500 + 1;
const int INF = 987654321;
int n, m;
vector<pair<int, int>> v[MAX];
long long dist[MAX];

int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int fr, to, dis;
    scanf("%d%d%d", &fr, &to, &dis);
    v[fr].push_back(make_pair(to, dis));
  }

  for (int i = 2; i <= n; i++)
  {
    dist[i] = INF;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dist[j] == INF)
        continue; //시작점과 연결되는지 체크
      for (auto &a : v[j])
      {
        int n = a.first, dn = a.second;

        if (dist[n] > dist[j] + dn)
        {
          dist[n] = dist[j] + dn;

          if (i == n)
          {
            printf("-1\n");
            return 0;
          }
        }
      }
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (dist[i] == INF)
    {
      printf("-1\n");
    }
    else
    {
      printf("%lld\n", dist[i]);
    }
  }
  return 0;
}