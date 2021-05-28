#include <stdio.h>

using namespace std;
const int max = 2500;

int n;
int arr[max][max];

int dnr[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dnc[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

int cnt[3];

void solve(int r, int c, int l)
{
  int start = arr[r][c];
  bool flag = true;
  for (int i = r; i < r + l; i++)
  {
    for (int j = c; j < c + l; j++)
    {
      if (start != arr[i][j])
      {
        flag = false;
        break;
      }
    }
    if (!flag)
      break;
  }

  if (flag)
  {
    cnt[start + 1]++;
    return;
  }

  l /= 3;
  for (int i = 0; i < 9; i++)
  {
    solve(r + dnr[i] * l, c + dnc[i] * l, l);
  }
}
int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  solve(0, 0, n);
  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", cnt[i]);
  }
  return 0;
}