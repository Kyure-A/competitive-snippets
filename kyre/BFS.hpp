#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  void BFS (int n, vector<vector<int>> graph, int start)
  {
    vector<int> distance(n, -1);
    queue<int> que; 

    distance[start] = 0; que.emplace(start);

    // Start
    while (!que.empty())
      {
	auto v = que.front(); que.pop();

	// v に隣接している頂点をすべて調べる
	for (auto near_v : graph[v])
	  {
	    if (distance[near_v] != -1) continue; 
        
	    distance[near_v] = distance[v] + 1;
	    que.emplace(near_v);
	  }
      }
  }
}
