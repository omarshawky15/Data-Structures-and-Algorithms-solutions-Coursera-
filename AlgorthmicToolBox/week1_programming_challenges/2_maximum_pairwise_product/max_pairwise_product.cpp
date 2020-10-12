#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();
    int i=0 , j=0 ;
    for(int k=1 ;k<numbers.size();k++){
        if(numbers[i] <numbers[k] )i =k ;
    }
    if(i==0)j=1 ;
    for(int k=1 ;k<numbers.size();k++){
        if(numbers[j] <numbers[k] && k!=i)j =k ;
    }
    return ((long long)numbers[i])*((long long)numbers[j]) ;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
