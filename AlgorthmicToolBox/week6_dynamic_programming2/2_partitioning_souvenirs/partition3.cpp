#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

long long partition3(vector<long long> &A, long long sum) {
    bool taken[A.size()];
    for (int i = 0; i < A.size(); i++)taken[i] = false;
    for (long long k = 0; k < 3; k++) {
        long long arr[A.size() + 1][sum + 1];
        for (long long i = 0; i <= A.size(); i++)
            for (long long j = 0; j <= sum; j++)
                arr[i][j] = 0;
        for (long long i = 1; i <= A.size(); i++)
            for (long long j = 0; j <= sum; j++)
                if (!taken[i - 1] && j - A[i - 1] >= 0)
                    arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - A[i - 1]] + A[i - 1]);
                else arr[i][j] = arr[i - 1][j];
        if (arr[A.size()][sum] != sum)return 0;
        long long w = sum;
        for (long long i = A.size(); i > 0; i--) {
            int j = i - 1;
            if (!taken[j] && arr[i][w] - A[j] == arr[j][w - A[j]]) {
                cout << A[j] << " ";
                w -= A[j];
                taken[j] = true;
            }
        }
        cout << endl;
    }

    return 1;
}

long long partition2(vector<long long> &A, long long sumA, long long sumB, long long sumC, int i) {
    if (i < 0) {
        if (sumA == 0 && sumB == 0 && sumC == 0)return 1;
        else return 0;
    }
    int val = 0;
    if (sumA - A[i] >= 0) {
        val = partition2(A, sumA - A[i], sumB, sumC, i - 1);
        if (val == 1)return 1;
    }

    if (sumB - A[i] >= 0) {
        val = partition2(A, sumA, sumB - A[i], sumC, i - 1);
        if (val == 1)return 1;
    }

    if (sumC - A[i] >= 0) {
        val = partition2(A, sumA, sumB, sumC - A[i], i - 1);
        if (val == 1)return 1;
    }
    return 0;
}

int main() {
    long long n;
    std::cin >> n;
    vector<long long> A(n);
    long long sum = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        cin >> A[i];
        sum += A[i];
    }
    //cout << sum << endl ;
    sort(A.begin(), A.end(), greater<>());
    if (sum % 3)cout << 0 << endl;
    else
        cout << partition3(A, sum / 3) << '\n';
    // cout << partition2(A, sum / 3,sum / 3,sum / 3,A.size()-1) << '\n';
}
