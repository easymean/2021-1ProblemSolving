#include <stdio.h>

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
  return a / gcd(a, b) * b;
}
int main(void)
{

  int a, b;
  scanf("%d%d", &a, &b);

  printf("%d\n%d\n", gcd(a, b), lcm(a, b));
  return 0;
}