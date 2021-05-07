#include <stdio.h>
#include <map>

using namespace std;
int n, m, acc;
long long answer;
int cnt[1001];
int main(void)
{
  scanf("%d %d", &n, &m);
  long long sum = 0;
  cnt[sum]++;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &acc);
    sum += acc;
    cnt[sum % m]++;
  }

  for (int i = 0; i < m; i++)
  {
    answer += (1ll * cnt[i] * (cnt[i] - 1)) / 2;
  }

  printf("%lld", answer);

  return 0;
}