#include <stdio.h>

using namespace std;
int arr[101][101];
int main(void)
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {

        if (arr[i][j] == 1)
        {
          continue;
        }

        arr[i][j] = (arr[i][k] & arr[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}