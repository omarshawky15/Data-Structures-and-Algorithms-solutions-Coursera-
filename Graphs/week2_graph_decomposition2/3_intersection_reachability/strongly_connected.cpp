#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::pair;

void revdfs(vector<vector<int>> &adj,vector<pair<int,int>> &when , bool vis[],int x,int &count){
    vis[x] = true;
    for(int i=0 ;i<adj[x].size();i++){
        if(!vis[adj[x][i]])revdfs (adj,when,vis,adj[x][i] ,count);
    }
    when.push_back(make_pair(++count ,x));
}

void dfs(vector<vector<int>> &adj,/*vector<int> &sets,*/ bool vis[],int x) {
    vis[x] = true;
    //sets.push_back(x);
    for(int i=0 ;i<adj[x].size();i++){
        if(!vis[adj[x][i]] )dfs (adj/*,sets*/,vis,adj[x][i]);
    }
}
int acyclic(vector<vector<int> > &adj) {
    if(adj.size()==0)return 0 ;
    vector<vector<int> > rev(adj.size());
    for(int i=0 ;i<adj.size();i++){
        for(int j=0 ;j<adj[i].size();j++){
            rev[adj[i][j]].push_back(i);
        }
    }
    vector<pair<int,int>> when ;
    bool vis [adj.size()];
    for(int i=0 ;i<adj.size();i++)vis[i] = false ;
    int count =0 ;
    for(int i=0 ;i<adj.size();i++){
        if(!vis[i])revdfs(rev,when,vis,i,count);
    }
    //sort(when.begin(),when.end(),greater<>());
    for(int i=0 ;i<adj.size();i++)vis[i] = false ;
    vector<vector<int>> sets ;
    int n = 0 ;
    for (int k = when.size()-1; k >=0; k--) {
        //vector<int> temp ;
        if(!vis[when[k].second]) {
            n++;
            dfs(adj, /*temp,*/ vis, when[k].second);
            //sets.push_back(temp);
        }
    }
    return n;
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
  std::cout << acyclic(adj);
}
