#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;
  
  template <typename T>
  class UnionFind
  {
  public:
    vector<T> coordinates; // 素集合を要素として管理
    vector<int> parent;
    vector<int> set_size;
  
    // constructor
    UnionFind (vector<T> pos) // 初期化するために要素を受け取る, n log n
    {
      sort(pos.begin(), pos.end());
      unique(pos.begin(), pos.end()); // 重複を除く
      coordinates = pos;
      parent = vector<int>(pos.size(), -1);
      set_size = vector<int>(pos.size(), 1);
    }
 
    int pos (const T &x) // log n
    {
      return lower_bound(coordinates.begin(), coordinates.end(), x) - coordinates.begin();
    }
 
    int root (const T &x) // log n
    {
      int px = pos(x);
      int ans = px;
    
      while (parent[ans] != -1)
	{
	  ans = parent[ans];
	}
    
      if (ans != px) parent[px] = ans;
    
      return ans;
    }
 
    bool merge (const T &x, const T &y)
    {
      const int rx = root(x);
      const int ry = root(y);
    
      if (rx == ry) return false;
    
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
  
    bool same (const T &x, const T &y) 
    {
      return root(x) == root(y);
    }

    int size (const T &x)
    {
      return set_size[root(x)];
    }
    
  };
}

