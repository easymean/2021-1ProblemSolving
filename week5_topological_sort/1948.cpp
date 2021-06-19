#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 10000 + 1;

int first, goal;
struct s
{
  int next, cost;
};

int indegree[MAX];
int dp[MAX];
bool visited[MAX];
vector<s> adj[MAX];
vector<s> back[MAX];
queue<int> q;

int main(void)
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    adj[from].push_back({to, cost});
    back[to].push_back({from, cost}); //역추적을 위해 필요
    indegree[to]++;
  }

  scanf("%d%d", &first, &goal);
  q.push(first);

  while (!q.empty())
  {
    int top = q.front();
    q.pop();

    for (auto a : adj[top])
    {
      int next = a.next, cost = a.cost;
      indegree[next]--;

      if (dp[top] + cost > dp[next])
      {
        dp[next] = dp[top] + cost;
      }

      if (indegree[next] == 0)
      {
        q.push(next);
      }
    }
  }

  int roads = 0;
  q.push(goal);

  while (!q.empty())
  {
    int top = q.front();
    q.pop();

    if (visited[top])
      continue;

    visited[top] = true;

    for (auto a : back[top])
    {
      if (dp[top] - dp[a.next] == a.cost)
      {
        q.push(a.next);
        roads++;
      }
    }
  }

  printf("%d\n%d\n", dp[goal], roads);
  return 0;
}