#include <stdio.h>
#define MAX 1000000

using namespace std;
bool arr[MAX + 1];
int main(void)
{
  arr[1] = true;
  for (int i = 2; i <= MAX; i++)
  {
    if (arr[i])
      continue;
    for (int j = i * 2; j <= MAX; j += i)
    {

      arr[j] = true;
    }
  }
  int a, b;
  scanf("%d%d", &a, &b);

  for (int i = a; i <= b; i++)
  {
    if (!arr[i])
      printf("%d\n", i);
  }

  return 0;
}