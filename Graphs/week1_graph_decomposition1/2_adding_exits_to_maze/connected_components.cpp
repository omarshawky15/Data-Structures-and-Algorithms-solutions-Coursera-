#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, bool arr[], int x) {
    arr[x] = true;
    for (int i = 0; i < adj[x].size(); i++) {
        if (!arr[adj[x][i]])dfs(adj, arr, adj[x][i]);
    }
}

int reach(vector<vector<int> > &adj) {
int ans = 0 ;
    bool arr[adj.size()];
    for (int i = 0; i < adj.size(); i++)arr[i] = false;
    for(int i=0 ;i<adj.size();i++) {
        if(!arr[i]){ans++;dfs(adj,arr,i);}
    }
    return ans;
}
int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << reach(adj);
}
