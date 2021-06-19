/*위상정렬+우선순위큐를 사용하면 쉽게 풀리는 문제*/
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32000 + 1;
int n, m;

vector<int> adj[MAX];
int indegree[MAX];
priority_queue<int, vector<int>, greater<int>> pq;
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d%d", &from, &to);
    indegree[to]++;
    adj[from].push_back(to);
  }

  for (int i = 1; i <= n; i++)
  {
    if (indegree[i] == 0)
    {
      pq.push(i);
    }
  }

  while (!pq.empty())
  {
    int x = pq.top();
    printf("%d ", x);
    pq.pop();

    for (auto a : adj[x])
    {
      indegree[a]--;
      if (indegree[a] == 0)
      {
        pq.push(a);
      }
    }
  }
  return 0;
}