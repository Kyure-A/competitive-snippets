namespace kyre
{
  template<class T> struct set
  {
    set<T> st;
    bool empty() const
    {
      return st.empty();
    }
    
    T size() const
    {
      return (T)st.size();
    }
    
  }
}
