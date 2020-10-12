#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <climits>
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;

void dfs(vector<vector<int>> &adj, int x, bool vis[]) {
    vis[x] = true;
    for (int i = 0; i < adj[x].size(); i++) {
        if (!vis[adj[x][i]])dfs(adj, adj[x][i], vis);
    }
}

void negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, long long dist[], vector<bool> &reachable,
                    int s) {
    for (int i = 0; i < adj.size(); i++)dist[i] = INT_MAX;
    dist[s] = 0;
    for (int a = 0; a < adj.size(); a++) {
        for (int i = 0; i < adj.size(); ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                if (dist[i] != INT_MAX && dist[i] + cost[i][j] < dist[adj[i][j]]) {
                    dist[adj[i][j]] = dist[i] + cost[i][j];
                }
            }
        }
    }
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < adj.size(); ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                if (dist[i] != INT_MAX && dist[i] + cost[i][j] < dist[adj[i][j]]) {
                    dist[adj[i][j]] = dist[i] + cost[i][j];
                    reachable[adj[i][j]] = false;
                }
            }
        }
    }
    bool vis[adj.size()];
    for (int i = 0; i < adj.size(); i++)vis[i] = false;
    for(int i=0;i<reachable.size();i++) {
        if(!reachable[i]&&!vis[i])dfs(adj, i, vis);
    }
    for (int j = 0; j < adj.size(); j++){if (vis[j])reachable[j] = false;vis[j] = false ;}
    //for (int i = 0; i < adj.size(); i++)vis[i] = false;
    dfs(adj, s, vis);
    for (int i = 0; i < adj.size(); i++)if (!vis[i])dist[i] = INT_MAX;

    }

int main() {
    int n, m, s;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    std::cin >> s;
    s--;
    vector<bool> reachable(n, true);
    long long dist[adj.size()];
    negative_cycle(adj, cost, dist, reachable, s);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)cout << "*" << endl;
        else if (!reachable[i]) cout << "-" << endl;
        else cout << dist[i] << endl;
    }
}
