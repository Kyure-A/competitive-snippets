#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../kyre/UnionFind.hpp"
#include <bits/stdc++.h>
using namespace std;

signed main ()
{
  int n, q; cin >> n >> q;

  kyre::UnionFind tree(n);
  
  while (q--)
    {
      int t, u, v; cin >> t >> u >> v;

      if (t == 0)
	{
	  tree.merge(u, v);
	}
      
      if (t == 1)
	{
	  if (tree.same(u, v)) cout << 1 << endl;
	  else cout << 0 << endl;
	}
    }
}
