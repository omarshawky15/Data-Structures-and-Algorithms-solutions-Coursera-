#include <iostream>
#include <vector>
using namespace std;
#include <climits>
#include <cmath>
int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;
    int arr[n-w+1];
    int maxi =A[0],mi=0 ,ni=-1,nextMaxi = INT_MIN;
    for(int i=1 ;i<w ;i++){
        if(A[i] >maxi){mi = i ;maxi = A[i];nextMaxi=INT_MIN;ni=-1;}
        else if(nextMaxi<=A[i] ){nextMaxi =max(nextMaxi , A[i] );ni = i;}
    }
    int i=w,j=0;
    arr[j] = maxi ;
    while(i<n) {
        if (A[i] >= nextMaxi) {
            nextMaxi = A[i];
            ni = i;
        }
        if (j == mi || nextMaxi >= maxi) {
            maxi = nextMaxi;
            mi = ni;
            nextMaxi = INT_MIN;
            ni = -1;
        }
        i++;j++;
        arr[j] = maxi;
    }
    for(int i=0 ;i<=n-w ;i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
    return 0;
}
