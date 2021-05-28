#include <stdio.h>

using namespace std;
long long a, b, c;

long long solve(long long n, long long m)
{
  n %= c;
  if (m == 1)
  {
    return n;
  }

  long long tmp = solve(n, m / 2);
  long long result = tmp + tmp;
  if (m & 1)
  {
    result = result % c + n % c;
  }
  return result % c;
}
int main(void)
{
  scanf("%lld%lld%lld", &a, &b, &c);
  long long result = 1;
  if (b > 1)
  {
    while (b > 0)
    {
      a %= c;
      if (b & 1)
      {
        result = solve((result % c), a);
      }
      a = solve(a, a);
      b = b / 2;
    }
    result %= c;
  }
  else
  {
    result = a % c;
  }

  printf("%lld", result);

  return 0;
}