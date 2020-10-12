#include <iostream>
using namespace std;
long long arr[(long long)1e4+1];
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fibonacci_fast(long long n,long long m) {
    int end  = min(n,(long long)1e4);
    arr[0] = 0 ;arr[1] = 1 ;
    long long first =0 , last =1 ;
    for(int i=1;i<end;i++){
        arr[i+1] = (first +last)% m ;
        first = last ;
        last = arr[i+1] ;
    }
    long long loop = end+1 ;
    long long k= 0 ,l = 0 ;
    for(long long j=m;j<end;j++){
        k= j ,l = 0 ;
        if(arr[0]==arr[k])
            while(l<j)if(arr[l]!=arr[k])break ;
            else {l++;k++;}
        if(l==j){loop = j ;break ; }
    }
    //cout << loop << endl ;
    return arr[n%loop ];
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_fast(n, m) << '\n';
}
