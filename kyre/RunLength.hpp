#include <bits/stdc++.h>

namespace kyre
{
  using namespace std;

  class RunLength
  {
  public: 
    string str;
    vector<pair<char, int>> encoded;
    map<char, vector<int>> index;
    bool is_encoded = false;
    
    RunLength(string s) : str(s) {}

    void encode ()
    {
      int count = 0;
      for (int left = 0; left < (int) str.size();)
	{
	  int right = left + 1;
	  for (; right < (int) str.size() and str[left] == str[right]; right++) {};
	  encoded.push_back({str[left], right - left});
	  left = right;
	  index[str[left]].emplace_back(count);
	  count++;
	}
      
      is_encoded = true;
    }

    vector<pair<char, int>> data()
    {
      if (is_encoded) encode();
      return encoded;
    }

    vector<int> find(const char c)
    {
      if (is_encoded) encode();
      return index[c];
    }
    
  };
}
