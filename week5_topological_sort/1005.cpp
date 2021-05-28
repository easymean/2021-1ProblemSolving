#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1000;
int t, n, k, w;
int time[MAX + 1];
int indegree[MAX + 1];
int dp[MAX + 1];
int main(void)
{
  scanf("%d", &t);
  while (t--)
  {
    vector<int> adj[MAX + 1];
    queue<int> q;

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &time[i]);
      dp[i] = 0;
      indegree[i] = 0;
    }
    int x, y;

    for (int i = 0; i < k; i++)
    {
      scanf("%d%d", &x, &y);
      indegree[y]++;
      adj[x].push_back(y);
    }
    scanf("%d", &w);

    for (int i = 1; i <= n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
        dp[i] = time[i];
      }
    }

    while (!q.empty())
    {
      int top = q.front();

      if (top == w)
      {
        break;
      }
      q.pop();

      for (int next : adj[top])
      {
        indegree[next]--;
        dp[next] = max(dp[next], dp[top] + time[next]);
        if (indegree[next] == 0)
        {
          q.push(next);
        }
      }
    }

    printf("%d\n", dp[w]);
  }
  return 0;
}