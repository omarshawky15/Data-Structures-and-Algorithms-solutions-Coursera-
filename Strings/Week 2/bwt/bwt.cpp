#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;
string BWT(const string& text) {
  string result = "";
  vector<string > v ;
  int sz= text.size() ;
  for(int j=sz-1 ;j>=0;j--){
      v.push_back(text.substr(j,sz) + text.substr(0,j) );
  }
  sort(v.begin(),v.end());
  for(int i=0 ;i<v.size();i++){
      result += v[i][sz-1];
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}