#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}
*/
bool comp (string s , string m){
    int l=0 , k =0 ,maxi = max(s.length(),m.length());
    for(int i=0 ; i<maxi;i++){
        if(s[l]<m[k])return false ;
        else if (s[l]>m[k])return true ;
        else {
            l+=1;
            l%=s.length();
            k+=1;
            k%=m.length();
        }
    }
    //cout << s << " " << m << endl ;
    return s[s.length()-1] > m[m.length()-1] ;
}
int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
    sort(a.begin(),a.end(),comp);
    for(int i=0 ;i<n ;i++){
        cout <<  a[i]  ;
    }
    cout << endl ;
}
