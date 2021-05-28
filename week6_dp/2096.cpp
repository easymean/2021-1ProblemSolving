//toggling

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int maxArr[3];
int minArr[3];
int n;
int arr[MAX][3];
int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int tmp1 = max(maxArr[0], maxArr[1]);
    int tmp2 = max(maxArr[1], maxArr[2]);
    maxArr[0] = tmp1 + a, maxArr[2] = tmp2 + c;
    maxArr[1] = max(tmp1, tmp2) + b;

    tmp1 = min(minArr[0], minArr[1]);
    tmp2 = min(minArr[1], minArr[2]);
    minArr[0] = tmp1 + a, minArr[2] = tmp2 + c;
    minArr[1] = min(tmp1, tmp2) + b;
  }

  int maxResult = max(maxArr[0], max(maxArr[1], maxArr[2]));
  int minResult = min(minArr[0], min(minArr[1], minArr[2]));
  printf("%d %d", maxResult, minResult);
  return 0;
}
