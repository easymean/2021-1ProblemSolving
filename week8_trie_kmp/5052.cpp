#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
struct node
{
  bool valid;
  int child[10];

  node()
  {
    valid = 0;
    memset(child, -1, sizeof(child));
  }
};

vector<node> trie;

int init()
{
  node x;
  trie.push_back(x);
  return (int)trie.size() - 1;
}

void add(int n, string &s, int idx)
{
  if (s.size() == idx)
  {
    trie[n].valid = 1;
    return;
  }
  int c = s[idx] - '0';
  if (trie[n].child[c] == -1)
  {
    int next = init();
    trie[n].child[c] = next;
  }

  add(trie[n].child[c], s, idx + 1);
}

bool find(int n, string &s, int idx)
{
  if (trie[n].valid)
    return true;
  if (idx == s.size() && !trie[n].valid)
    return true;

  if (idx == s.size())
    return false;

  int c = s[idx] - '0';

  if (trie[n].child[c] == -1)
  {
    return false;
  }

  return find(trie[n].child[c], s, idx + 1);
}

int t, n;
string s;
int main(void)
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
  {
    cin >> n;
    trie.clear();
    init();
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      if (trie.size() > 1 && find(0, s, 0))
      {
        flag = false;
      }

      add(0, s, 0);
    }
    if (flag)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}