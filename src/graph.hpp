#ifndef __GRAPH_H__
#define  __GRAPH_H__

#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <functional>

template<class V>
class graph
{
  private:
    std::unordered_map<V, std::unordered_set<V>> adj_list;
    void dfs(V& ,std::function<void(V)>&, std::unordered_set<V>&);

  public:
    graph(){};
    graph(const std::unordered_map<V, std::unordered_set<V>>& al): adj_list(al){};
    std::unordered_set<V> getVertices() const;
    void add(V, const std::unordered_set<V>&);
    void bfs(V, std::function<void(V)>);
    void dfs(V, std::function<void(V)>);
    vector<V> graph<V>::tological_sort();
};

template <class V> void graph<V>::add(V v, const std::unordered_set<V>& neighboors)
{
  adj_list[v].insert(neighboors.begin(), neighboors.end());
  // to force creation of an entry in hashtable for neighbours
  for(const V& neigh : neighboors)
    adj_list[neigh];
}

template <class V> std::unordered_set<V> graph<V>::getVertices() const
{
  std::unordered_set<V> s;
  for (auto& pair : adj_list)
    s.insert(pair.first);
  return s;
}

/*
use bfs to reach all nodes frome entry
Appply to each node function f
*/
template <class V> void graph<V>::bfs(V entry, std::function<void(V)> f)
{
  std::unordered_set<V> seen;
  std::deque<V> next;
  next.push_back(entry);
  seen.insert(entry);

  while(next.size() != 0)
  {
      V& vertex = next.front();
      f(vertex);

      for(auto& neigh : adj_list[vertex])
      {
        if(seen.find(neigh) == seen.end())
        {
          next.push_back(neigh);
          seen.insert(neigh);
        }
      }

      next.pop_front();
  }
}

/*
use dfs to reach all nodes frome entry
Appply to each node function f
*/

template <class V> void graph<V>::dfs(V entry, std::function<void(V)> f)
{
  std::unordered_set<V> seen;
  seen.insert(entry);
  f(entry);

  for(V neigh : adj_list[entry])
  {
    if(seen.find(neigh) == seen.end())
    {
      seen.insert(neigh);
      dfs(neigh, f, seen);
    }
  }
}

template <class V> void graph<V>::dfs(V& entry ,std::function<void(V)>& f, std::unordered_set<V>& seen)
{
  f(entry);
  for(V neigh : adj_list[entry])
  {
    if(seen.find(neigh) == seen.end())
    {
      seen.insert(neigh);
      dfs(neigh, f, seen);
    }
  }
}

#endif