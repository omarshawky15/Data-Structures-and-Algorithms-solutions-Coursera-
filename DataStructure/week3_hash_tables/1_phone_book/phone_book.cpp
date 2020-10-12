#include <iostream>
#include <vector>
#include <string>
#include <utility>
using std::string;
using std::vector;
using std::cin;
using namespace std ;
struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}
vector <vector<pair<int,string>>> v ((int)1e5 +1);
long long hsh (long long num){
    return (((253*num +233)%(long long)(1e7+19))%((long long)(1e5)));
}
vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result ;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    for (size_t i = 0; i < queries.size(); ++i) {
        long long h = hsh(queries[i].number);
        int j = 0;
        if (queries[i].type == "add") {
            for (; j < v[h].size(); j++) {
                if (v[h][j].first == queries[i].number) {
                    v[h][j].second = queries[i].name;
                    break;
                }
            }
            if (j == (int)v[h].size())v[h].push_back(make_pair(queries[i].number, queries[i].name));
        } else if (queries[i].type == "del") {
            for (; j < v[h].size(); j++) {
                if (v[h][j].first == queries[i].number) {
                    swap(v[h][j], v[h][v[h].size() - 1]);
                    v[h].pop_back();
                    break;
                }
            }
        } else {
            for (; j < v[h].size(); j++) {
                if (v[h][j].first == queries[i].number) {
                    result.push_back(v[h][j].second);
                    break;
                }
            }
            if (j==v[h].size())result.push_back("not found");
        }
    }
    return result;

}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
