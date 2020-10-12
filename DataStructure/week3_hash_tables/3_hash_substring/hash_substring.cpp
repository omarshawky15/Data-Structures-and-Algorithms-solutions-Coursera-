#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(std::vector<long long int> output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

long long p = 1e7 + 9, x;

long long calcPattern(string s) {
    long long ans = 0;
    x = 1;
    for (int i = 0; i < s.size(); i++) {
      //  cout << s[i] *x << " ";
        ans = (ans * 34 + s[i]) % p;
        x = (x * 34) % p;
    }
    //cout << endl ;
    return ans;
}
std::vector<long long> get_occurrences(const Data &input) {
    const string &s = input.pattern, t = input.text;
    long long pf ,ps = calcPattern(s), pt = calcPattern(t.substr(0, s.size()));
    std::vector<long long> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i) {
        if (pt == ps && t.substr(i, s.size()) == s)
            ans.push_back(i);
        //pf = calcPattern(t.substr(i,s.size()));
        //long long a = t[i] * x  , b= t[i + s.size()] , c= pt * 34;
        if (i + s.size() != t.size())pt = ((pt * 34 - t[i] * x + t[i + s.size()]) % p + p)%p;
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
