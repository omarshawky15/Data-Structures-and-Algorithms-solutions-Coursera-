#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(const vector<string> &patterns) {
    trie t;
    edges tempE;
    t.push_back(tempE);
    for (int i = 0; i < patterns.size(); i++) {
        int a = 0, b = 0;
        while (b <= patterns[i].size()) {
            if (b==patterns[i].size() || t[a].count(patterns[i][b]) == 0) {
                //create new edge and node ;
                for (int k = b; k < patterns[i].size(); k++) {
                    t[a].insert(make_pair(patterns[i][k], t.size()));
                    a = t.size();
                    edges e1;
                    t.push_back(e1);
                }
                t[a].insert(make_pair('$', -1));
                break;
            } else {
                a = t[a][patterns[i][b]];
                b++;
            }
        }
    }
    return t;
}

int check(const string &text, int start, trie &t) {
    int i = start, a = 0;
    while (i <= text.size()) {
        if (t[a].count('$'))return start;
        else  if (i < text.size() && t[a].count(text[i])){
            a = t[a][text[i]];
            i++;
        }
        else return -1;
    }
    return -1;
}

vector<int> solve(const string &text, const vector<string> &patterns) {
    vector<int> result;
    trie t = build_trie(patterns);
    for (int i = 0; i < text.size(); i++) {
        int x = check(text, i, t);
        if (x != -1)result.push_back(x);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string t;
    cin >> t;

    int n;
    cin >> n;

    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }

    vector<int> ans;
    ans = solve(t, patterns);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < (int) ans.size()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
