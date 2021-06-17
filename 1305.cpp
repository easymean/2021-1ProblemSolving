#include <iostream>
#include <string>

using namespace std;
int n;
string s;
int fail[1000001];
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;

  for (int i = 1, j = 0; i < n; i++)
  {
    while (j > 0 && s[i] != s[j])
      j = fail[j - 1];

    if (s[i] == s[j])
      fail[i] = ++j;
  }

  cout << n - fail[n - 1];
  return 0;
}