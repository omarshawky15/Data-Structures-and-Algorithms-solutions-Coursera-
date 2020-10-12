#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
    vector<int> num;
    vector<char> op ;
    for(int i=0 ;i<exp.size();i+=2){
        num.push_back(exp[i] - '0');
    }
    for(int i=1 ;i<exp.size();i+=2){
        op.push_back(exp[i]);
    }
    long long arr[num.size()][num.size()][2];
    for(int i=0 ;i<num.size();i++) {
        for (int j = 0; j <num.size(); j++) {
            arr[i][j][0] =arr[i][j][1] = 0;
        }
        }
    for (int j = 0; j <num.size(); j++) {arr[j][j][0] =arr[j][j][1] = num[j] ;}

    for(int s=1 ;s<num.size();s++){
        for(int i=0 ;i<num.size()-s;i++){
            int j= i+s ;
            long long mini =INT_MAX,maxi =INT_MIN;
            for(int k=0 ; k<s;k++){
                for(int a =0 ;a<2;a++) {
                    for (int b = 0; b < 2; b++) {
                        long long val = eval(arr[i][i + k][a], arr[i + k+1][j][b], op[i + k]);
                        mini = min(val, mini);
                        maxi = max(val, maxi);
                    }

                }}
            arr[i][j][0] = mini ;
            arr[i][j][1] = maxi ;
        }
    }


        return arr[0][num.size()-1][1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
