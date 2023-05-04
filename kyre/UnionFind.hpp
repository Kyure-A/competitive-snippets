#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;
  
  class UnionFind
  {
  public:
    vector<long long> parent;
    vector<long long> set_size;

    // constructor
    UnionFind (long long n): parent(n), set_size(n, 1LL)
    {
      for (long long i = 0; i < n; ++i) parent[i] = i;
    }
    void init(long long n)
    {
      parent.resize(n);
      set_size.assign(n, 1LL);
      for (long long i = 0; i < n; ++i) parent[i] = i; 
    }

    long long root (long long x) // find (path halving)
    {
      while (parent[x] != x)
	{
	  parent[x] = parent[parent[x]];
	  x = parent[x];
	}

      return x;
    }

    bool merge (long long x, long long y) // union by size
    {
      long long rx = root(x);
      long long ry = root(y);

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
    }

    bool same (long long x, long long y)
    {
      return root(x) == root(y);
    }

    long long size(long long x)
    {
      return set_size[root(x)];
    }

  };
}
