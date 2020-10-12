#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;
int getparent(vector<int>&sets, int x) {
    if(sets[x] != x)return sets[x] = getparent(sets,sets[x]);
    return x ;
}
double minimum_distance(const vector<long long> &x,const vector<long long> &y) {
  double result = 0.;
  vector<pair<long long,pair<int,int>>> adj(x.size()) ;
  vector<int> sets (x.size());
  int count =1 ;
    for(int i=0 ;i<x.size();i++) {
        sets[i] = i ;
        for (int j = i+1; j < x.size(); j++) {
            adj.push_back(make_pair((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]),make_pair(i,j)));
        }
    }
    sort(adj.begin(),adj.end());
    for(int i=0 ;count<x.size()&& i<adj.size();i++){
        int xparent= getparent(sets,adj[i].second.first) , yparent = getparent(sets,adj[i].second.second) ;
        if(xparent!=yparent){
            sets[xparent] = sets[yparent];
            result+=sqrt(adj[i].first);
            count ++ ;
        }
    }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
