#include <stdio.h>

using namespace std;
int n, m;
int arr[10000];
int main(void)
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int sum = arr[0];
  int l = 0, r = 0;
  int answer = 0;
  while (l < n && r < n)
  {
    if (sum == m)
    {
      answer++;
      sum += arr[++r];
    }
    else if (sum > m)
    {
      sum -= arr[l++];
    }
    else
    {
      sum += arr[++r];
    }
  }
  printf("%d", answer);
  return 0;
}