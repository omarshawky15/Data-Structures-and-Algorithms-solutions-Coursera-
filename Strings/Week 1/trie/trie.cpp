#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;
using namespace std;
trie build_trie(const vector<string> & patterns) {
  trie t;
  edges tempE ;
  t.push_back(tempE);
  for(int i=0 ;i<patterns.size();i++){
      int a =0 ,b=0;
    auto j=t[a].begin() ;
    while(b<patterns[i].size()) {
        for (; j != t[a].end(); j++) {
            if ((*j).first == patterns[i][b])break;
        }
        if (j == t[a].end()) {
            //create new edge and node ;
            //t[a].insert(make_pair(patterns[i][b], t.size()));
            for (int k = b; k < patterns[i].size(); k++) {
                t[a].insert(make_pair(patterns[i][k], t.size()));
                a=t.size();
                edges e1;
                t.push_back(e1);
            }
            break ;
        }
        a = (*j).second;
        j = t[a].begin();
        b++;
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}