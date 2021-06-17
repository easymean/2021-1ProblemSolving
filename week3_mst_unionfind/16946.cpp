#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;
const int MAX = 1000;
int x, y, groupNum;

int arr[MAX + 1][MAX + 1];    // 원래 배열
int group[MAX + 1][MAX + 1];  //배열에서 0인 칸이 몇번째 그룹인지 표시
bool visit[MAX + 1][MAX + 1]; /// bfs에서 이미 그룹화되어있는 0인지 확인
int num[MAX * MAX + 1];       // n번째 그룹이 몇 명의 인원을 가지고 있는지 표시

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool isValid(int r, int c)
{
  if (r < 0 || c < 0 || r > x - 1 || c > y - 1)
    return false;
  return true;
}

void bfs(int r, int c)
{
  groupNum++;
  queue<pair<int, int>> q;
  vector<pair<int, int>> v; // 그룹화할 좌표값들

  int cnt = 1;
  q.push(make_pair(r, c));
  visit[r][c] = true;
  v.push_back(make_pair(r, c));
  while (!q.empty())
  {
    int fr = q.front().first;
    int fc = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = fr + dr[i];
      int nc = fc + dc[i];

      if (isValid(nr, nc) && !visit[nr][nc] && arr[nr][nc] == 0)
      {
        q.push(make_pair(nr, nc));
        visit[nr][nc] = true;
        v.push_back(make_pair(nr, nc));
        cnt++;
      }
    }
  }
  for (auto a : v)
  {
    group[a.first][a.second] = groupNum;
  }
  num[groupNum] = cnt;
  //printf("%d has %d\n", groupNum, cnt);
}
int main(void)
{
  scanf("%d%d", &x, &y);

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (arr[i][j] == 0 && !visit[i][j])
      {
        bfs(i, j);
      }
    }
  }

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (arr[i][j] == 1)
      {
        int cnt = 1;
        set<int> s; // 인접한 그룹 확인
        for (int k = 0; k < 4; k++)
        {
          int ni = i + dr[k], nj = j + dc[k];
          if (!isValid(ni, nj) || arr[ni][nj] == 1)
          {
            continue;
          }

          int adjGroup = group[ni][nj];
          if (s.find(adjGroup) == s.end())
          {
            //printf("(%d, %d) is next to %d\n", i, j, adjGroup);
            s.insert(adjGroup);
            cnt += num[adjGroup];
          }
        }
        cnt %= 10;
        printf("%d", cnt);
      }
      else
      {
        printf("%d", 0);
      }
    }
    printf("\n");
  }

  return 0;
}