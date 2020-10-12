#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using namespace std;
// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  return result;
}

vector<int> BWT(const string& text) {
    vector<int> result(text.size());
    vector<pair<string, int> > v;
    int sz = text.size();
    for (int j = sz - 1; j >= 0;  j--) {
        v.push_back(make_pair(text.substr(j, sz) + text.substr(0, j), j));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        result[i] = v[i].second;
    }
    return result;
}
int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BWT(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
