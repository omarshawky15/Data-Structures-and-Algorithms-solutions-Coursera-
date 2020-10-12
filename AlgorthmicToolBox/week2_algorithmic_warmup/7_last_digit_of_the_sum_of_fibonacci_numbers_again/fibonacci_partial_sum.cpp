#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long arr[(long long)1e4+1];
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long int sum(long long i) {
    if(i<0)return 0 ;
    long long sum =0 ;
    for(int j=0 ;j<=i ;j++){sum+=arr[j];sum%=10;}
    return sum ;
}

long long fibonacci_fast(long long n,long long m) {
    int end  = min(n,(long long)1e4);
    arr[0] = 0 ;arr[1] = 1 ;
    long long first =0 , last =1 ;
    for(int i=1;i<61;i++){
        arr[i+1] = (first +last)% 10 ;
        first = last ;
        last = arr[i+1] ;
    }
    return (-sum((n-1)%60) + sum((m)%60) +10)%10;
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
int bin(vector<int> &stops ,int x ){
    int l =0 ,h = stops.size();
    while(h-l >3){
        int mid = h -(h-l)/2;
        if (stops[mid]<=x)l=mid ;
        else h=mid;
    }
    int ans = -1 ;
    for(int i=l ;i<h;i++){
        if(stops[i] <= x)ans = i ;
        else break ;
    }
    return ans;
}
int main () {
    int n ,m;
    cin >> n >>m ;
    vector<int> stops (m);
    vector<int> necs;
    for(int i=0; i<m; i++)cin >> stops[i];
    int l ;
    for(int i=3 ;i<n ;i+=3){

        int x = bin(stops,i);

        if(x==-1 || stops[x]==i-3){cout << -1 << endl;return 0 ;}
        else {necs.push_back(stops[x]);i=stops[x] ;}
    }
    for(int i=0; i<necs.size(); i++)cout << necs[i] << " ";
    return 0 ;
}