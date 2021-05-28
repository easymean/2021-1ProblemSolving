#include <stdio.h>

using namespace std;
int a, b, c;

int pow(int base, int exp)
{
  base %= c;
  if (exp == 1)
    return base;

  int tmp = pow(base, exp / 2);
  int res = (1LL * (tmp % c) * (tmp % c)) % c;
  if (exp % 2 == 1)
    res = (1LL * (res % c) * base) % c;
  return res;
}
int main(void)
{
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", pow(a, b));
  return 0;
}