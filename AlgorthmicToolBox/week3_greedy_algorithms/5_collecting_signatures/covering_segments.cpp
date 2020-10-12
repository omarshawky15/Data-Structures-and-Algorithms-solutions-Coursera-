#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp (pair<int,int> a,pair<int,int> b ){
    return a.second < b.second;
}
vector<int> optimal_points(vector<pair<int,int>> &segments) {
  vector<int> points;
  int start =0 ,end=0;
  sort(segments.begin(),segments.end(),comp);
    /*for (size_t i = 0; i < segments.size(); ++i) {
        std::cout << segments[i].first <<" "<<  segments[i].second<<endl;
    }*/
  /*for(int i=0 ;i<segments.size();i++){
      if(segments[start].second>=segments[i].first){
        if(segments[start].second<=segments[i].second){
            end = i ;
        }else {
            points.push_back(segments[i].second);
            start =i+1;
            end = i+1;
        }
    }else {
        points.push_back(segments[start].second);
        start = i;
        end = i;
    }
}
    if(start!= segments.size())points.push_back(segments[start].second);
  */
  int idx = 0 ;
  while(idx<segments.size()){
      int s1 = segments[idx].second;
      while(idx<segments.size()-1&& s1>=segments[idx+1].first)idx++;
      points.push_back(s1);
      idx++;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<pair<int,int>> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  vector<int> points = optimal_points(segments);

  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
