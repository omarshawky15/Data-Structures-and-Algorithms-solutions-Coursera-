#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <climits>
using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std;

double minimal_distance(vector<pair<long long , long long>> &vector);
int main() {
  size_t n;
  std::cin >> n;
  vector<pair<long long , long long >> v ;
  for (size_t i = 0; i < n; i++) {
      int x , y ;
    std::cin >> x >> y;
    v.push_back(make_pair(x,y));
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(v) << "\n";
}
bool comp(const pair<long long,long long> &p1 ,const  pair<long long ,long long> &p2 ){
    if(p1.second == p2.second)return p1.first<p2.first;
    else
    return p1.second<p2.second;
}
double minimal_distance(vector<pair<long long, long long>> &v) {
    long long mini =LONG_LONG_MAX;
    sort(v.begin(),v.end());
    int sz = v.size()-1 ;
    for(int i=0;i<sz ;i++){
        mini = min(mini ,
                (v[i].first-v[i+1].first)*(v[i].first-v[i+1].first) +(v[i].second-v[i+1].second)*(v[i].second-v[i+1].second));
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<sz;i++){
        mini = min(mini ,
                   (v[i].first-v[i+1].first)*(v[i].first-v[i+1].first) +(v[i].second-v[i+1].second)*(v[i].second-v[i+1].second));
    }
    //cout << mini << " " << LONG_LONG_MAX <<" "<< sqrt(mini)<<" ";
    return sqrt(mini);
}
