#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using namespace std;
static int noCh = 5 ;
// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.

int chartoidx (char ch)
{
    switch (ch){
        case '$' :
            return 0 ;
        case 'A' :
            return 1 ;
        case 'C' :
            return 2 ;
        case 'G' :
            return 3 ;
        default:
            return 4 ;
    }
}
vector<int> sortDoubles (const string &text
        , vector<int> &order
        ,const vector<int>&clas
        ,int L){
    vector<int > count(clas[order[text.size()-1]]+1, 0) ;
    vector<int> newOrder (order.size(),0);
    for(int i=0 ;i<text.size();i++){
        count[clas[i]]++ ;
    }
    for (int j = 1; j < count.size(); ++j) {
        count[j] +=count[j-1] ;
    }
    for (int i =text.size()-1; i >=0 ; --i) {
        int start = (order[i] - L  + text.size())%text.size() ;
        newOrder[--count[clas[start]]] = start;
    }
    return newOrder ;
}
vector<int> computeClasses (vector<int> &order
        ,vector<int>&clas
        ,int L){
    vector<int> newclas (order.size());
   newclas[order[0]] =0  ;
    for(int i=1 ;i<order.size();i++){
        int cur = order[i] , prev = order[i-1] ;
        int mid = (cur +L)%order.size() , prevmid = (prev+L)%order.size() ;
        if((clas[cur] != clas[prev]) || (clas[mid] !=clas[prevmid]))newclas[cur] = newclas[prev] +1 ;
        else newclas[cur] = newclas[prev] ;
    }
    return newclas;
}
vector<int> BuildSuffixArray(const string& text) {
  vector<int > count(noCh, 0), clas(text.size(),0) ,order(text.size(), 0);
    for(int i=0 ;i<text.size();i++){
        clas[i] = chartoidx(text[i]);
        count [clas[i]] ++ ;
    }
    for (int j = 1; j < count.size(); ++j) {
        count[j] +=count[j-1] ;
    }
    for(int i=text.size()-1 ;i>=0;i--){
        order[--count[clas[i]]] = i;
    }
    int L = 1;
    while(L<text.size()){
        order = sortDoubles(text,order,clas,L);
        clas = computeClasses(order,clas,L);
        L*=2;
    }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
