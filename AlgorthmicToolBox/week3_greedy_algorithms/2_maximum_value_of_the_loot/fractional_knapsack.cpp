#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

double get_optimal_value(double capacity,const  vector<double> &weights, const vector<double> &values) {
  double value = 0.0;
  vector<pair<double,double>>units (weights.size());
  for(int i=0 ;i<weights.size();i++){
      units[i] = make_pair(values[i]/weights[i],weights[i]);
  }
  sort(units.begin(),units.end(),greater<>());
  int i=0 ;
  double maxi ,eps = 1e-10;
  while(i<units.size()&&capacity>eps){
      maxi = min(capacity,units[i].second);
      value+=maxi*units[i].first;
      capacity-=maxi;
      i++;
  }
  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
