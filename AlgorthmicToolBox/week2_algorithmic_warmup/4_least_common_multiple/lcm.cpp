#include <iostream>

int gcd_naive(long long a, long long b) {
    if(b==0 )return a ;
    return gcd_naive(b , a%b);
}
long long lcm_naive(long long a, long long b) {
return (a*b)/gcd_naive(a,b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
