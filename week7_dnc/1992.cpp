#include <stdio.h>

using namespace std;
const int max = 64;
int n;

int arr[max][max];

int isValid(int r, int c, int l)
{
  for (int i = r; i < r + l; i++)
  {
    for (int j = c; j < c + l; j++)
    {
      if (arr[i][j] != arr[r][c])
      {
        return -1;
      }
    }
  }
  return arr[r][c];
}

void solve(int r, int c, int l)
{
  int result = isValid(r, c, l);
  if (result != -1)
  {
    printf("%d", result);
    return;
  }
  l /= 2;
  printf("(");
  for (int i = r; i < r + 2 * l; i += l)
  {
    for (int j = c; j < c + 2 * l; j += l)
    {
      solve(i, j, l);
    }
  }
  printf(")");
}

int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }
  solve(0, 0, n);
  return 0;
}