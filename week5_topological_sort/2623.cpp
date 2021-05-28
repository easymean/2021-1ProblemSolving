#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;
int n, m;
int indegree[MAX + 1];
int tmp[MAX + 1];
vector<int> adj[MAX + 1];
queue<int> q;
vector<int> result;
int main(void)
{
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++)
  {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++)
    {
      scanf("%d", &tmp[j]);
    }

    for (int j = 0; j < num - 1; j++)
    {
      int x = tmp[j], y = tmp[j + 1];
      adj[x].push_back(y);
      indegree[y]++;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }
  int cnt = 0;
  while (!q.empty())
  {
    int top = q.front();
    result.push_back(top);
    q.pop();
    cnt++;

    for (int next : adj[top])
    {
      indegree[next]--;
      if (indegree[next] == 0)
      {
        q.push(next);
      }
    }
  }

  if (cnt != n)
  {
    printf("0");
  }
  else
  {
    for (auto a : result)
    {
      printf("%d\n", a);
    }
  }
  return 0;
}