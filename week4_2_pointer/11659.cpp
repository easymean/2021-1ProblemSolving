#include <stdio.h>

using namespace std;
int n, m;
int arr[100001];
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    arr[i] = arr[i - 1] + tmp;
  }

  for (int i = 0; i < m; i++)
  {
    int start, end;
    scanf("%d%d", &start, &end);
    printf("%d\n", arr[end] - arr[start - 1]);
  }
  return 0;
}