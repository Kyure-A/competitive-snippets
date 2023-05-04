#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  class PairedUnionFind
  {
  public:
    map<pair<int, int>, pair<int, int>> parent;
    map<pair<int, int>, int> set_size;
 
    // constructor
    PairedUnionFind (int h, int w): parent(), set_size()
    {
      for (int i = 0; i < h; ++i)
	{
	  for (int j = 0; j < w; ++j)
	    {
	      parent[{i, j}] = {i, j};
	      set_size[{i, j}] = 1;
	    }
	}
    }
 
    pair<int, int> root (pair<int, int> x) // find (path halving)
    {
      while (parent[x] != x)
	{
	  parent[x] = parent[parent[x]];
	  x = parent[x];
	}
 
      return x;
    }
 
    bool merge (pair<int, int> x, pair<int, int> y) // union by size
    {
      pair<int, int> rx = root(x);
      pair<int, int> ry = root(y);
 
      if (rx == ry) return false;
      else if (set_size[rx] < set_size[ry]) swap(rx, ry);
      // Operations
      parent[ry] = rx;
      set_size[rx] += set_size[ry];
      return true;
    }
 
    bool same (pair<int, int> x, pair<int, int> y)
    {
      return root(x) == root(y);
    }
 
    int size(pair<int, int> x)
    {
      return set_size[root(x)];
    }
 
  };
}