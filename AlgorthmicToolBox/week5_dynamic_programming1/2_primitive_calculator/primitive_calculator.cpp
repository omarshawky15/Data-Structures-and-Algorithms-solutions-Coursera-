#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

vector<int> optimal_sequence2(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence(int m) {
    vector<int> v(m+5 , INT_MAX);
    v[0] = 0 ;
    v[1] = 0 ;
    v[2] = 1 ;
    v[3] = 1 ;
    for(int i=1 ;i<=m;i++){
        v[i] = min(v[i-1] + 1,v[i]);
        if(i%3 ==0)v[i] = min(v[i/3] + 1,v[i]);
        if(i%2 ==0)v[i] = min(v[i/2] + 1,v[i]);
    }
    vector<int> seq ;
    while(m!=1){
        if(v[m-1] + 1 == v[m]){seq.push_back(m);m--;continue;}
        if(m%2 ==0 && v[m/2] + 1 == v[m]){seq.push_back(m);m/=2;continue;}
        if(m%3 ==0 && v[m/3] + 1 == v[m]){seq.push_back(m);m/=3;
            continue;}
    }
    seq.push_back(1);
    reverse(seq.begin(),seq.end());
    return seq;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
