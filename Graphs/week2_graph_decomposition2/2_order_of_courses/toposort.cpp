#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
}

void dfs(vector<vector<int>> &adj, vector<int> &order, bool vis[],int x,int &count) {
    vis[x] = true;
    for(int i=0 ;i<adj[x].size();i++){
        if(!vis[adj[x][i]] )dfs (adj,order,vis,adj[x][i],count);
    }
    order.push_back(x);
}
vector<int> toposort(vector<vector<int> > adj) {
vector<int> order;
  bool vis[adj.size()] ;
  for(int i=0 ;i<adj.size();i++)vis[i] = false ;
  int count =0;
    for(int i=0 ;i<adj.size();i++){
        if(!vis[i])dfs (adj,order,vis,i,count);
    }
  return order;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (int i = order.size()-1; i>=0; i--) {
    std::cout << order[i] + 1 << " ";
  }
}
