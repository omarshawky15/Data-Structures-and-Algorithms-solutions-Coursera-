#include <iostream>
using namespace std;
long long arr[(long long)1e4+1];

long long int sum(long long int i);

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_fast(long long n) {
    int end  = min(n,(long long)1e4);
    arr[0] = 0 ;arr[1] = 1 ;
    long long first =0 , last =1 ;
    for(int i=1;i<61;i++){
        arr[i+1] = (first +last)% 10 ;
        first = last ;
        last = arr[i+1] ;
    }
    /*int loop = -1 ;
    for(int j=m;j<end;j++){
        int k= j ,l = 0 ;
        if(arr[0]==arr[k])
            while(l<j)if(arr[l]!=arr[k])break ;
                else {l++;k++;}
        if(l==j){loop = j ;break ; }

    }*/
    //cout << loop << endl ;
    return sum(n%60);
}

long long int sum(long long i) {
    long long sum =0 ;
    for(int j=0 ;j<=i ;j++){sum+=arr[j];sum%=10;}
    return sum ;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n);
}
