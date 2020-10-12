#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int lcs3(vector<int> &str1, vector<int> &str2, vector<int> &str3) {
    int arr[str1.size() + 1][str2.size() + 1][str3.size() + 1];
    for (int i = 0; i <= str1.size(); i++)for (int j = 0; j <= str2.size(); j++) arr[i][j][0] = 0;
    for (int i = 0; i <= str2.size(); i++)for (int j = 0; j <= str3.size(); j++) arr[0][i][j] = 0;
    for (int i = 0; i <= str1.size(); i++)for (int j = 0; j <= str3.size(); j++) arr[i][0][j] = 0;
    for (int i = 1; i <= str1.size(); i++)
        for (int j = 1; j <= str2.size(); j++) {
            for (int k = 1; k <= str3.size(); k++) {
                arr[i][j][k] = INT_MIN;
                if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
                    arr[i][j][k] = max(arr[i][j][k],
                                       arr[i - 1][j - 1][k -1] +1);
                else {
                    arr[i][j][k] = max(arr[i][j][k],
                                       max(arr[i - 1][j - 1][k - 1],
                                               max(arr[i - 1][j][k], max(arr[i][j - 1][k],
                                                       max(arr[i][j - 1][k - 1],
                                                               max(arr[i - 1][j][k -1],
                                                                       max(arr[i - 1][j -1][k],
                                                                               arr[i][j][k -1])))))));
                }
            }
        }
    return arr[str1.size()][str2.size()][str3.size()];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
