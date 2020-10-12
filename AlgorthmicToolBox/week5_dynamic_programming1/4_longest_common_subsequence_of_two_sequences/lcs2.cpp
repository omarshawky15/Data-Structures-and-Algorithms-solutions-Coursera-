#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int lcs2(const vector<int> &str1,const vector<int> &str2) {
    int arr[str1.size()+1][str2.size()+1];
    for(int i=0 ;i<=str1.size();i++)arr[i][0] = 0;;
    for(int i=0 ;i<=str2.size();i++)arr[0][i] = 0;;
    for(int i=1 ;i<=str1.size();i++)
        for(int j=1 ;j<=str2.size();j++) {
            arr[i][j] = INT_MIN;
            if (str1[i-1] == str2[j-1])arr[i][j] = max(arr[i][j], arr[i - 1][j - 1]+1);
            else {
                arr[i][j] = max(arr[i][j], max(arr[i - 1][j - 1] , max( arr[i - 1][j], arr[i][j - 1])));
            }
        }

    return arr[str1.size()][str2.size()];
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
