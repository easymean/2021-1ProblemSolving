#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000000;
int fail[MAX + 1];
vector<int> res;
int main(void)
{
  string t, p;
  getline(cin, t);
  getline(cin, p);
  int n = t.length();
  int m = p.length();

  for (int i = 1, j = 0; i < m; i++)
  {
    while (j > 0 && p[i] != p[j])
      j = fail[j - 1];
    if (p[i] == p[j])
      fail[i] = ++j;
  }

  for (int i = 0, j = 0; i < n; i++)
  {
    while (j > 0 && t[i] != p[j])
      j = fail[j - 1];

    if (t[i] == p[j])
    {
      if (j == m - 1)
      {
        res.push_back(i - m + 1);
        j = fail[j];
      }
      else
      {
        j++;
      }
    }
  }
  cout << res.size() << "\n";
  for (auto a : res)
  {
    cout << a + 1 << " ";
  }
  return 0;
}