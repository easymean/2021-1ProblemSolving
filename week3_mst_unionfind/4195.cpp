#include <iostream>
#include <map>

using namespace std;

const int MAX = 100000 + 1;
int t, f;
int parent[MAX * 2];
int child[MAX * 2];

int findParent(int x)
{
  if (x == parent[x])
  {
    return x;
  }
  return parent[x] = findParent(parent[x]);
}

void merge(int x, int y)
{
  x = findParent(x);
  y = findParent(y);
  if (x != y)
  {
    parent[y] = x;
    child[x] += child[y];
  }
}
int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    map<string, int> mp;

    cin >> f;
    int idx = 1;
    string a, b;

    for (int i = 1; i <= 2 * f; i++)
    {
      parent[i] = i;
      child[i] = 1;
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

      if (findParent(mp[a]) == findParent(mp[b]))
      {
        cout << child[findParent(mp[a])] << "\n";
      }
      else
      {
        merge(mp[a], mp[b]);
        cout << child[findParent(mp[b])] << "\n";
      }
    }
  }
  return 0;
}