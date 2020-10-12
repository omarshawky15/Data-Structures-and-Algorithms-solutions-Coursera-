#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using std::vector;
using std::queue;
using namespace std;
int bipartite(vector<vector<int> > &adj) {
    int vis[adj.size()] ;
    for(int i=0 ;i<adj.size();i++)vis[i] =0 ;
    queue<int> q;
    for(int i=0 ;i<adj.size();i++) {
        if(vis[i] == 0) {
            q.push(i);
            vis[i] = -1;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < adj[x].size(); i++) {
                    if (vis[adj[x][i]] == 0) {
                        vis[adj[x][i]] = -vis[x];
                        q.push(adj[x][i]);
                    } else if (vis[adj[x][i]] == vis[x])return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
