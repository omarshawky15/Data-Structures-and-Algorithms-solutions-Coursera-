#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<long long> s1(100001);
vector<long long> s2(100001);
vector<long long> x1(100001);
vector<long long> x2(100001);
vector<long long> t1(100001);
vector<long long> t2(100001);
string s, t;
long long p = 1e9 + 7, m = 1e9 + 9;

struct Answer {
    size_t i, j, len;
};

void Solver() {
    int j;
    s1[0] = 0;
    s2[0] = 0;
    t1[0] = 0;
    t2[0] = 0;
    int i = 0, sz = min(s.size(), t.size());
    for (; i < sz; i++) {
        j = i + 1;
        s1[j] = (x1[i] * s[i] + s1[i]) % p;
        s2[j] = (x2[i] * s[i] + s2[i]) % m;
        t1[j] = (x1[i] * t[i] + t1[i]) % p;
        t2[j] = (x2[i] * t[i] + t2[i]) % m;
      }
    while (i < s.size()) {
        j = i + 1;
        s1[j] = (x1[i] * s[i] + s1[i]) % p;
        s2[j] = (x2[i] * s[i] + s2[i]) % m;
        i++;
    }
    while (i < t.size()) {
        j = i + 1;
        t1[j] = (x1[i] * t[i] + t1[i]) % p;
        t2[j] = (x2[i] * t[i] + t2[i]) % m;
        i++;
    }
}

bool ask(int a, int b, int l) {
    long long d1 = s1[a + l] - s1[a] + p, f1 = t1[b + l] - t1[b] + p;
    long long d2 = s2[a + l] - s2[a] + m, f2 = t2[b + l] - t2[b] + m;
    return (d1 * x1[max(b - a, 0)]) % p == ((f1 * x1[max(a - b, 0)]) % p) &&
           (d2 * x2[max(b - a, 0)]) % m == ((f2 * x2[max(a - b, 0)]) % m);
}

pair<int,int> hsh(vector<long long > &s1 ,vector<long long > &s2 ,int a, int l,int ln) {
    long long d1 = s1[a + l] - s1[a] + p;
    long long d2 = s2[a + l] - s2[a] + m;
    return make_pair(static_cast<int>((d1 * x1[ln-a]) % p) , static_cast<int>((d2 * x2[ln-a]) % m ));}
/*Answer solve() {
    Answer ans = {0, 0, 0};
    Solver();
    for (size_t len = min(s.size(), t.size()); len > 0; len--) {
        set<pair<int, int>> st;
        int maxi = max(s.size(),t.size());
        for (size_t i = 0; i + len <= s.size(); i++) {
            st.insert(hsh(s1, s2, i, len,maxi));
        }
        for (size_t j = 0; j + len <= t.size(); j++) {
            //if (ask(i, j, len))return {i, j, len};
            if(st.count(hsh(t1,t2,j,len,maxi)))return {}
        }
    }
    return ans;
}*/
/*Answer solve() {
    Answer ans = {0, 0, 0};
    Solver();
    for (size_t len = min(s.size(), t.size()); len > 0; len--) {

        for (size_t i = 0; i + len <= s.size(); i++)
            for (size_t j = 0; j + len <= t.size(); j++)
                if (ask(i, j, len))return {i, j, len};
    }
    return ans;
}*/
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    x1[0] = 1;
    x2[0] = 1;
    for(int i=0 ;i<100001 ;i++) {
        x1[i + 1] = (x1[i] * 34) % p;
        x2[i+1] = (x2[i] * 34) % m;
    }
        while (cin >> s >> t) {
        auto ans = solve();
        cout << ans.i << " " << ans.j << " " << ans.len << "\n";
    }
}
