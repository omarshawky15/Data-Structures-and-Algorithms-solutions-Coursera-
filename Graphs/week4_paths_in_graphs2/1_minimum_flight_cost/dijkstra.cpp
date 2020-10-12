#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std ;
long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
bool vis [adj.size()] ;
    for (int i = 0; i < adj.size(); ++i) {
        vis[i] = false ;
    }
    priority_queue<pair<long long ,long long >,vector<pair<long long ,long long>>,greater<>> pq ;
pq.push(make_pair(0,s));
while (!pq.empty()){
    long long x = pq.top().second, w = pq.top().first;
    pq.pop();
    vis[x] = true ;
    if(x==t)return w ;
    for (int i = 0; i <adj[x].size() ; ++i) {
        if(!vis[adj[x][i]]){
            pq.push(make_pair(w+cost[x][i],adj[x][i]));
        }
    }
}
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
