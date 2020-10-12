#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using namespace std ;
int bin(const vector<int> &stops ,int x ){
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

int compute_min_refills(int dist, int tank,const vector<int> & stops) {
    int count=0 ;
    for(int i=tank ;i<dist ;i+=tank){
        int x = bin(stops,i);
        if(x==-1 || stops[x]==i-tank)
            return -1 ;
        else {count ++ ;
        i=stops[x] ;
        }
    }
    return count;
    }

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
