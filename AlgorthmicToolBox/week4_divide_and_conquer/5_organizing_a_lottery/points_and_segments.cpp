#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool comp (const pair<int,int> &p1 ,const pair<int,int>&p2 ){
    return p1.first<p2.first;
}
vector<int> fast_count_segments(vector<int> &starts,vector<int> &ends, vector<pair<int,int>> &points,int arr[]){
    vector<int> arr2(points.size());
    sort(points.begin(),points.end());
    for(int i=0 ; i<starts.size();i++){
    int start = lower_bound(points.begin(),points.end(),make_pair(starts[i],0),comp) - points.begin();
    int end = upper_bound(points.begin(),points.end(),make_pair(ends[i],0),comp) - points.begin();
    arr[start]++;
      arr[end]--;
  }
    for(int i=1 ;i<=points.size();i++){arr[i] +=arr[i-1];}
    for(int i=0 ;i<points.size();i++)
        arr2[points[i].second] =arr[i];
    return arr2 ;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<pair<int,int>> points(m);
  int arr[m+1];
  for (int i = 0; i < points.size(); i++) {
    std::cin >> points[i].first;
    points[i].second = i;
    arr[i] = 0 ;
  }
  arr[m] =0 ;
  //use fast_count_segments
  vector<int> arr2 = fast_count_segments(starts, ends, points,arr);
  for (int i = 0; i < m; i++) {
      int x = arr2[i];
      cout <<x << ' ';
  }
}
