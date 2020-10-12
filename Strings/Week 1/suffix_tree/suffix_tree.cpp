#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
typedef map<char, int> edges;
typedef vector<edges> trie;

void build_trie(string &text, trie &t, int &i) {
    int a = 0, b = i;
    while (b <= text.size()) {
        if (b == text.size() || t[a].count(text[b]) == 0) {
            //create new edge and node ;
            for (int k = b; k < text.size(); k++) {
                t[a].insert(make_pair(text[k], t.size()));
                a = t.size();
                edges e1;
                t.push_back(e1);
            }
            t[a].insert(make_pair('$', -1));
            break;
        } else {
            a = t[a][text[b]];
            b++;
        }
    }
}/*
int check (string &text , string &match,int i){
    int j=0,k=i ;
    for(;j<text.size() && k < match.size();k++,j++){
        if(text[j] != match[k]){
            break ;
        }
    }
}*//*
void build_trie2(string &text, trie2 &t, int &i) {
    int a = 0, b = i;*/
/*
    while (b <= text.size()) {
        if (b == text.size()|| t[a].count(text[b]) == 0) {
            //create new edge and node ;
            for (int k = b; k < text.size(); k++) {
                t[a].insert(make_pair(text[k], t.size()));
                a = t.size();
                edges e1;
                t.push_back(e1);
            }
            t[a].insert(make_pair('$', -1));
            break;
        } else {
            a = t[a][text[b]];
            b++;
        }
    }*//*
    int ans =-1 ;
    for(int i=0 ;i<t[a].size();i++){

    }
}
*/
trie solve(string &text) {
    text = text.substr(0, text.size() - 1);
    trie t;
    edges tempE;
    t.push_back(tempE);
    t[0].insert(make_pair('$', -1));
    for (int i = 0; i < text.size(); i++) {
        build_trie(text, t, i);
    }
    return t;
}

// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
queue<int> st;

void traverse(trie &text) {
    st.push(0);
    while (!st.empty()) {
        int x = st.front();
        st.pop();
        for (auto i = text[x].begin(); i != text[x].end(); i++) {
            //string s = "";
            cout << ((*i).first);
            int j = (*i).second;
            while (j != -1 && text[j].size() == 1) {
                cout << (*(text[j].begin())).first;
                j = (*(text[j].begin())).second;
            }
            if (j != -1)st.push(j);
            cout << endl;
        }
    }
}

void dfs(trie &text, int x) {
    if(x == -1){
        cout << endl ;
        return ;
    }
    if(text[x].size()>1)cout << endl ;
    for (auto i = text[x].begin(); i != text[x].end(); i++) {
        cout << ((*i).first);
        dfs(text, (*i).second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string text;
    cin >> text;
    trie edges = solve(text);
    // cout << edges.size()<<endl ;
 //   traverse(edges);
 dfs(edges,0);
 /*
    vector<string> v =
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }*/
    return 0;
}
