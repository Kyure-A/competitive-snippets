#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  struct Edge
  {
    int to;

    int cost;
  };

  using Graph = vector<vector<Edge>>;

  using Pair = pair<long long, int>;

  vector<long long> Dijkstra(const Graph& graph, int start)
  {
    constexpr long long INF = (1LL << 60);
    
    vector<long long> distances(graph.size(), INF);
    
    priority_queue<Pair, vector<Pair>, greater<Pair>> que;
    
    que.emplace((distances[start] = 0), start);

    while (!que.empty())
      {
	const long long distance = que.top().first, from = que.top().second; que.pop();

	if (distances[from] < distance) continue;
	
	for (const auto& edge : graph[from])
	  {
	    const long long d = (distances[from] + edge.cost);

	    if (d < distances[edge.to]) que.emplace((distances[edge.to] = d), edge.to);
	  }
      }

    return distances;
  }
}
