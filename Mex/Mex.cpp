#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;
  int Mex(set<int> st)
  {
    int st_max = *st.rbegin();

    for (int i = 0; i < st_max; ++i)
      {
	if (st.find(i) == st.end()) return i;
      }

    return st_max + 1;
  };
}
