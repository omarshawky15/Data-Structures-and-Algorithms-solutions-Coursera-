#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int k = floor(-0.5 + sqrt(0.25+(double)2*n));
  for(int i =1 ;i<k;i++){
      summands.push_back(i);
      n-=i ;
  }
  if(n!=0)summands.push_back(n);
    return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
