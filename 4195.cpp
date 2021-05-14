#include <iostream>
#include <map>

using namespace std;
int t, f;
map<string, int> mp;
int parent[100000];

int findParent(int x)
{
  if (x == parent[x])
  {
    return x;
  }
  return findParent(parent[x]);
}
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> f;
    int idx = 0;
    string a, b;

    for (int i = 1; i < f; i++)
    {
      parent[i] = i;
    }

    for (int i = 0; i < f; i++)
    {
      cin >> a >> b;
      if (mp[a] == 0)
      {
        mp[a] = idx++;
      }
      if (mp[b] == 0)
      {
        mp[b] = idx++;
      }
    }
  }
  return 0;
}