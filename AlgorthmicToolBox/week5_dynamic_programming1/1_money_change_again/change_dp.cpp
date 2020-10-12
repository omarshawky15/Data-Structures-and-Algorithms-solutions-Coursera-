#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int get_change(int m) {
    vector<int> v(m+5 , INT_MAX);
    v[0] = 0 ;
    v[1] = 1 ;
    v[3] = 1 ;
    v[4] = 1 ;
    for(int i=1 ;i<=m;i++){
        v[i] = min(v[i-1] + 1,v[i]);
        if(i-3 >=0)v[i] = min(v[i-3] + 1,v[i]);
        if(i-4 >=0)v[i] = min(v[i-4] + 1,v[i]);
    }
  return v[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
