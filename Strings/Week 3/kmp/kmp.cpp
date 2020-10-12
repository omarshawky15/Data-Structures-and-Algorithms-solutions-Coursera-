#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
    string s = pattern + "$" + text ;
    vector <int> arr (s.size(),0);
    int border = 0;
    for (int i = 1; i < arr.size(); ++i) {
        while(border > 0 && s[border] != s[i] ){
            border = arr[border-1];
        }
        if(s[border] !=s[i])arr[i] = 0 ;
        else arr[i] = ++border ;
    }
    int minus = 2*pattern.size();
    for (int i = minus; i < arr.size(); ++i) {
        if(arr[i]==pattern.size()){
            result.push_back(i-minus) ;
        }
    }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
