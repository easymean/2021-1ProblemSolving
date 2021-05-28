#include <stdio.h>
#include <vector>

using namespace std;
const int MAX = 4000000 + 1;
int n, answer;
bool arr[MAX];
vector<int> v;
int main(void)
{
  scanf("%d", &n);

  if (n == 1)
  {
    return !printf("0");
  }
  arr[1] = true;
  for (int i = 2; i <= n; i++)
  {
    if (arr[i])
      continue;
    for (int j = i * 2; j <= n; j += i)
    {
      arr[j] = true;
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (arr[i])
      continue;
    v.push_back(i);
  }

  int left = 0, right = 0;
  int sum = v[0];
  int sze = v.size() - 1;
  while (left <= sze && right <= sze)
  {
    if (sum == n)
    {
      answer++;
      sum += v[++right];
    }
    else if (sum < n)
    {

      sum += v[++right];
    }
    else
    {
      sum -= v[left++];
    }
  }
  printf("%d", answer);
  return 0;
}