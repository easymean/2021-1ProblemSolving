#include <stdio.h>
#define MAX 1000000;

using namespace std;
int n;
bool arr[MAX + 1];
int main(void)
{

  arr[1] = true;
  for (int i = 2; i <= MAX + 1; i++)
  {
    if (arr[i])
      continue;
    for (int j = i * 2; j <= MAX + 1; j += i)
    {
      arr[j] = true;
    }
  }
  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
    {
      break;
    }

    int l = 3, r = n;
    while (l < r)
  }
  return 0;
}