#include <stdio.h>
#define MAX 1000000 + 1

using namespace std;
int n;
bool arr[MAX];
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
  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
    {
      return 0;
    }
    bool flag = false;
    for (int l = 3, r = n - 3; l <= r; l += 2, r -= 2)
    {
      if (!arr[l] && !arr[r])
      {
        printf("%d = %d + %d \n", n, l, r);
        flag = true;
        break;
      }
    }

    if (!flag)
    {
      printf("Goldbach's conjecture is wrong.");
    }
  }

  return 0;
}