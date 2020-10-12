#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
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



vector<int> FindOccurrences(const string& pattern, const string& bwt, const vector<int>& suffix_array,const vector<int> &firstocc ,const vector<vector<int>> &occ) {
  vector<int> result;
    int top = 0, bottom = bwt.size()-1;
    for (int i = pattern.size() - 1; i >= 0; i--) {
        int idx = chartoidx(pattern[i]);
        top = firstocc[idx] + occ[top][idx];
        bottom = firstocc[idx] + occ[bottom + 1][idx] - 1;
        if (bottom < top)return result;
    }
for(int i=top ; i<=bottom ;i++){
    result.push_back(suffix_array[i]);
}
  return result;
}
void computeOcc(vector<vector<int>> &occ ,vector<int> &firstocc,const string &bwt , const vector<int> &suffix_array){
    vector<int>count(noCh,0);
    int sz = bwt.size() , idx = chartoidx(bwt[sz-2]) ;
    occ[1][idx] =1 ;
    count[0] = 1 ;
    for(int i=1 ;i<sz;i++){
        idx = suffix_array[i] ;
        if(idx ==0 )idx = sz ;
        occ[i+1][chartoidx(bwt[idx-1])]++;
        for (int j = 0; j < 5; ++j) {
            occ[i+1][j] += occ[i][j];
        }
        count[chartoidx(bwt[suffix_array[i]])]++;
    }/*
    for (int j = 0; j < 5; ++j) {
        occ[bwt.size()][j] += occ[bwt.size() - 1][j];
    }*/
    for (int l = 1; l < firstocc.size(); ++l) {
        firstocc[l] = firstocc[l-1] + count[l-1] ;
    }

}
int main() {
  char buffer[100001];
  scanf("%s", buffer);
  string text = buffer;
  text += '$';
  vector<int> suffix_array = BuildSuffixArray(text);
    vector<vector<int>> occ (text.size()+1, vector<int>(noCh,0));
    vector<int>firstocc(noCh,0);
    computeOcc(occ ,firstocc, text , suffix_array);
    int pattern_count;
  scanf("%d", &pattern_count);
  vector<bool> occurs(text.length(), false);
  for (int pattern_index = 0; pattern_index < pattern_count; ++pattern_index) {
    scanf("%s", buffer);
    string pattern = buffer;
    vector<int> occurrences = FindOccurrences(pattern, text, suffix_array,firstocc,occ);
    for (int j = 0; j < occurrences.size(); ++j) {
      occurs[occurrences[j]] = true;
    }
  }
  for (int i = 0; i < occurs.size(); ++i) {
    if (occurs[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
