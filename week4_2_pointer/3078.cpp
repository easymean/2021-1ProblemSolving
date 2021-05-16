#include <iostream>
#include <vector>

using namespace std;

const int MAX = 300000 + 1;
int n, k;
string tmp;
long long cnt[21];
int len[MAX];
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    len[i] = tmp.length();
  }
  int s = 0, e = 0;
  long long answer = 0;
  cnt[len[0]] = 1;
  while (s <= n - 1)
  {

    if (e <= k - 1)
    {
      e++;
      cnt[len[e]]++;
      continue;
    }

    if (cnt[len[s]] > 1)
    {
      answer += cnt[len[s]] - 1;
    }
    cnt[len[s]]--;
    s++;

    if (e < n - 1)
    {
      e++;
      cnt[len[e]]++;
    }
  }

  cout << answer << "\n";
  return 0;
}