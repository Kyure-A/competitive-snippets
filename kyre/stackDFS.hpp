#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  void stackDFS (int n, vector<vector<int>> graph, int start)
  {
    stack<int> stk;
    stk.emplace(start);
    vector<bool> seen(n, false);
    seen[start] = true;
  
    while (!stk.empty())
      {
	auto v = stk.top(); stk.pop();

	for (auto near_v : graph[v])
	  {
	    if (seen[near_v]) continue;
	    seen[near_v] = true;
	    stk.emplace(near_v);
	  }
      }
  }
}
