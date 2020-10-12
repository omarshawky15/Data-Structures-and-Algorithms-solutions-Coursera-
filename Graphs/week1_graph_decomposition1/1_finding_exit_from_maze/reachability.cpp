#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using namespace std;
int dfs(vector<vector<int> > &adj, bool arr[], int x, int y) {
    arr[x] = true;
    if (x == y)return 1;
    for (int i = 0; i < adj[x].size(); i++) {
        if(!arr[adj[x][i]] && dfs(adj, arr, adj[x][i], y))return 1 ;
    }
    return 0;
}

int reach(vector<vector<int> > &adj, int x, int y) {
    bool arr[adj.size()];
    for (int i = 0; i < adj.size(); i++)arr[i] = false;

    return dfs(adj,arr, x, y);
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
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}
