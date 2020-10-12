#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;
int chartoidx (char ch)
{
    switch (ch){
        case 'A' :
            return 0 ;
        case 'C' :
            return 1 ;
        case 'G' :
            return 2 ;
        case 'T' :
            return 3 ;
        default:
            return 4 ;
    }
}
string InverseBWT(const string &bwt) {
    vector<pair<string,int>> v(bwt.size()+1, make_pair("",0));
    //vector<string> w(bwt.size());
    vector<int > firstocc (5,-1),lastocc (5,0);
    int sz = bwt.size(), sz1 = sz - 1;
    for (int i = 0; i < sz; i++) {
        v[i].first += bwt[i];
        v[i].second = lastocc[chartoidx(bwt[i])]++;
      //  w[i] = v[i].first;
    }
    //sort(w.begin(),w.end());
    firstocc[0] = 1 ;
    for(int i=1 ;i<4 ;i++){
        firstocc[i] = lastocc[i-1] +firstocc[i-1]  ;
    }
    string text = "$" ;
    int x= 0 ;
    for(int i=0 ;i<sz1;i++){
        text += bwt[x];
        x = firstocc[chartoidx(bwt[x])]+ v[x].second;
    }reverse(text.begin(),text.end());
    return text;
}

int main() {
    string bwt;
    cin >> bwt;
    cout << InverseBWT(bwt) << endl;
    return 0;
}
