#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  long double euclideanDistance(pair<int, int> a, pair<int, int> b)
  {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
  }

  long double euclideanDistance(int a_x, int a_y, int b_x, int b_y)
  {
    return sqrt(pow(a_x - b_x, 2) + pow(a_y - b_y, 2));
  }
}
