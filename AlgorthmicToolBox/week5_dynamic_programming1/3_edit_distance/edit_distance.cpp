#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
    int arr[str1.size()+1][str2.size()+1];
    for(int i=0 ;i<=str1.size();i++)arr[i][0] = i;
    for(int i=0 ;i<=str2.size();i++)arr[0][i] = i;
    for(int i=1 ;i<=str1.size();i++)
        for(int j=1 ;j<=str2.size();j++) {
            arr[i][j] = INT_MAX;
            if (str1[i-1] == str2[j-1])arr[i][j] = min(arr[i][j], arr[i - 1][j - 1]);
            else {
                arr[i][j] = min(arr[i][j], min(arr[i - 1][j - 1]+1 , min( arr[i - 1][j] + 1 , arr[i][j - 1] + 1)));
            }
        }

    return arr[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
