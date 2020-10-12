#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int optimal_weight(int w, const vector<int> &v) {
    for(int i=0 ;i<=v.size();i++){
        vector<int>temp ;
        for(int j=0 ;j<=w;j++)
            temp.push_back(0) ;
        arr.push_back(temp);
        }
    for(int i=1 ;i<=v.size();i++)for(int j=1 ;j<=w;j++){
        arr[i][j] = arr[i-1][j] ;
        if(j-v[i-1] >= 0)arr[i][j] = max(arr[i][j] , arr[i-1][j-v[i-1]] + v[i-1]);
    }
  return arr[v.size()][w];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
