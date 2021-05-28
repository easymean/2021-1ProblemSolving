#include <stdio.h>

using namespace std;
bool arr[1001];

void eratos()
{
  arr[1] = true;
  for (int i = 2; i <= 1000; i++)
  {
    if (arr[i])
      continue;
    for (int j = i * 2; j <= 1000; j += i)
    {
      arr[j] = true;
    }
  }
}
int main(void)
{
  eratos();
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if (!arr[tmp])
      sum++;
  }
  printf("%d\n", sum);
  return 0;
}