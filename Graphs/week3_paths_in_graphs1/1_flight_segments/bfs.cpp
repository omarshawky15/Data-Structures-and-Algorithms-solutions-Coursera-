#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using std::vector;
using std::queue;
using namespace std ;
int distance(vector<vector<int> > &adj, int s, int t) {
    bool vis[adj.size()] ;
    for(int i=0 ;i<adj.size();i++)vis[i] = false ;
    int count =0 ;
    queue<pair<int,int>> q;
    q.push(make_pair(s,0));
    while(!q.empty()){
        int x = q.front().first,w = q.front().second;
        if(x==t)return w ;
        q.pop();
        for(int i=0 ;i<adj[x].size();i++){
            if(!vis[adj[x][i]]){
                vis[adj[x][i]] = true ;
                q.push(make_pair(adj[x][i],w +1 ));
            }
        }
    }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
