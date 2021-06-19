//ㅎ 마지막에 \n 안넣어서 30분동안 인스타함 ㅎ
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int MAX = 1000;
int t, k, m, p;
int indegree[MAX + 1];
int stash[MAX + 1];
int num[MAX + 1];
int main(void)
{
  scanf("%d", &t);
  while (t--)
  {

    scanf("%d%d%d", &k, &m, &p);
    memset(indegree, 0, sizeof(int) * (m + 1));
    memset(stash, 0, sizeof(int) * (m + 1));
    memset(num, 1, sizeof(int) * (m + 1));

    vector<int> adj[MAX + 1];
    queue<int> q;

    for (int i = 0; i < p; i++)
    {
      int from, to;
      scanf("%d%d", &from, &to);
      adj[from].push_back(to);
      indegree[to]++;
    }

    for (int i = 1; i <= m; i++)
    {
      if (indegree[i] == 0)
      {
        stash[i] = 1;
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int top = q.front();
      q.pop();

      for (auto a : adj[top])
      {
        indegree[a]--;
        if (stash[top] > stash[a])
        {
          stash[a] = stash[top];
          num[a] = 1;
        }
        else if (stash[top] == stash[a])
        {
          num[a]++;
        }

        if (indegree[a] == 0)
        {
          q.push(a);
          if (num[a] > 1)
          {
            stash[a] += 1;
          }
        }
      }
    }

    printf("%d %d\n", k, stash[m]);
  }
  return 0;
}