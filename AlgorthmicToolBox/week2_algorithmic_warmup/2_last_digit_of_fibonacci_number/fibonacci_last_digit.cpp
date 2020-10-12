#include <iostream>

int get_fibonacci_last_digit_naive(int n) {

        long long first =0 , last =1 ;
        long long temp ;
        for(int i=1;i<n;i++){
            temp = (first +last)%10 ; ;
            first = last ;
            last = temp ;
        }
        if(n==0)return first ;
        return last ;
    }

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
