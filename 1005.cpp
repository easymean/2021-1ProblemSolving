#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 1000;
int t, n, k, w;
int time[MAX + 1];
int indegree[MAX + 1];
int dp[MAX + 1];
queue<int> q;
int main(void)
{
  scanf("%d", &t);
  while (t--)
  {
    vector<int> adj[MAX + 1];
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &time[i]);
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
      }
    }

    int sum = time[w];
    while (!q.empty())
    {
      int top = q.front();
      q.pop();

      for (int prev : adj[top])
      {
      }
    }
  }
  return 0;
}