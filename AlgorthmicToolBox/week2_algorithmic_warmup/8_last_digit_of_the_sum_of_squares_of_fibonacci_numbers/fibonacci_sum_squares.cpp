#include <iostream>
#include <vector>
using namespace std;
long long arr[(long long)1e4+1];

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}


bool comp (string s , string m){
    int l=0 , k =0 ,maxi = max(s.length(),m.length());
    for(int i=0 ; i<maxi;i++){
        if(s[l]<m[k])return false ;
        else if (s[l]>m[k])return true ;
        else {
            //if(l+1<s.length())
            l+=1;
            l%=s.length();
            //if(k+1!=m.length())

            k+=1;
            k%=m.length();
        }
    }
    return false ;
}
/*int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_fast(from, to) << '\n';
*//*
int main() {
int n ;
cin >> n ;
vector < string > v (n);
for(int i=0 ;i<n ;i++){
    cin >> v[i] ;
}
sort(v.begin(),v.end(),comp);
    for(int i=0 ;i<n ;i++){
        cout <<  v[i] << " " ;
    }
    return 0 ;
}*/
long long int sum(long long i) {
    if(i<0)return 0 ;
    long long sum =0 ;
    for(int j=0 ;j<=i ;j++){sum+=arr[j]*arr[j];sum%=10;}
    return sum ;
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
    return sum(n%60);
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n);
}
