#include <iostream>
#include <vector>

using namespace std;
int n, k;
vector<int> v;
int main(void)
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    v.push_back(tmp.size());
  }

  int s = 0, e = 1, answer = 0;
  int sze = v.size() - 1;
  while (s <= sze && e <= sze)
  {
    if (e - s <= k)
    {
      e++;
      if (v[s] == v[e])
        answer++;
    }
    else
    {
      s++;
    }
  }
  cout << answer << "\n";
  return 0;
}