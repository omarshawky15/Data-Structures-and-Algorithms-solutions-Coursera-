#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <climits>
#include <cmath>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using namespace  std;
class StackWithMax {
    int maxi =INT_MIN ,maxiNo = 0 ;
    //int nextMaxi =INT_MIN ,nextMaxiNo = -1 ;
    vector<pair<pair<int,int>,pair<int,int>>> stack;

  public:

    void Push(int value) {
        if (maxi < value) {
                stack.push_back(make_pair(make_pair(value, 1), make_pair(maxi, maxiNo)));

                maxi = value;
                maxiNo = 1;
            } else if (maxi == value) {
                maxiNo++;
                stack.push_back(make_pair(make_pair(value, maxiNo), make_pair(-1, -1)));
            }else stack.push_back(make_pair(make_pair(value, -1), make_pair(-1, -1)));
    }
    void Pop() {
        assert(stack.size());
        if(stack.back().first.first==maxi){
            maxiNo--;
            if(maxiNo==0){
                maxi = stack.back().second.first ;
                maxiNo = stack.back().second.second;
            }
        }
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return maxi;
    }
};
int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}