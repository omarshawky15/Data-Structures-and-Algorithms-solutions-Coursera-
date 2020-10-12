#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int get_majority_element(vector<int> &a) {
    sort(a.begin(),a.end());
    int n2 = round(a.size()/2.0) , n1 = a.size()/2.0;
    //cout << n2 <<" "<< n1 << endl ;
    if(n1==n2)n2++;
    for(int i=0 ;i<a.size()-n2+1;i++){
        if(a[i]==a[i+n2-1])return 1 ;
    }
    return 0 ;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << get_majority_element(a) << endl;
}
