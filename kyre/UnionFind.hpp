#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;
  
  class UnionFind
  {
  public:
    vector<int> parent;
    vector<int> set_size;

    // constructor
    UnionFind (int n): parent(n), set_size(n, 1LL)
    {
      for (int i = 0; i < n; ++i) parent[i] = i;
    }
    void init(int n)
    {
      parent.resize(n);
      set_size.assign(n, 1LL);
      for (int i = 0; i < n; ++i) parent[i] = i; 
    }

    int root (int x) // find (path halving)
    {
      while (parent[x] != x)
	{
	  parent[x] = parent[parent[x]];
	  x = parent[x];
	}

      return x;
    }

    bool merge (const int x, const int y) // union by size
    {
      const int rx = root(x);
      const int ry = root(y);

      if (rx == ry) return false;

      // Operations
      else if (set_size[rx] < set_size[ry])
	{
	  parent[rx] = ry;
	  set_size[ry] += set_size[rx];
	}
      else
	{
	  parent[ry] = rx;
	  set_size[rx] += set_size[ry];
	}

      return true;
    }

    bool same (const int x, const int y)
    {
      return root(x) == root(y);
    }

    int size (const int x)
    {
      return set_size[root(x)];
    }

  };
}
