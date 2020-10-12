#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static const int noCh = 5;

int chartoidx(char ch) {
    switch (ch) {
        case 'A' :
            return 0;
        case 'C' :
            return 1;
        case 'G' :
            return 2;
        case 'T' :
            return 3;
        default:
            return 4;
    }
}

void PreprocessBWT(const string &bwt,
                     vector<int> &firstocc,
                     vector<vector<int>> &arr) {
    vector<int> v(bwt.size() + 1, 0);
    vector<int> lastocc(noCh, 0);
    int sz = bwt.size(), sz1 = sz - 1;
    for (int i = 0; i < sz; i++) {
        int idx = chartoidx(bwt[i]);
        arr[i + 1][idx] = 1;
        v[i] = lastocc[idx]++;
        for (int j = 0; j < noCh; j++)arr[i + 1][j] += arr[i][j];
    }
    firstocc[0] = 1;
    for (int i = 1; i < 4; i++) {
        firstocc[i] = lastocc[i - 1] + firstocc[i - 1];
    }
    /*
    string text = "$";
    int x = 0;
    for (int i = 0; i < sz1; i++) {
        text += bwt[x];
        x = firstocc[chartoidx(bwt[x])] + v[x];
    }
    reverse(text.begin(), text.end());
    return text;
*/
}

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string &pattern,
                     const string &bwt, const vector<int> &firstocc,
                     const vector<vector<int>> &arr) {
    int top = 0, bottom = bwt.size()-1;
    for (int i = pattern.size() - 1; i >= 0; i--) {
        int idx = chartoidx(pattern[i]);
        top = firstocc[idx] + arr[top][idx];
        bottom = firstocc[idx] + arr[bottom + 1][idx] - 1;
        if (bottom < top)return 0;
    }
    return bottom - top + 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string bwt;
    cin >> bwt;
    int pattern_count;
    cin >> pattern_count;
    // Start of each character in the sorted list of characters of bwt,
    // see the description in the comment about function PreprocessBWT
    vector<int> firstocc(noCh, 0);
    vector<vector<int>> arr(bwt.size() + 1, vector<int>(noCh, 0));
    //map<char, int> starts;
    // Occurrence counts for each character and each position in bwt,
    // see the description in the comment about function PreprocessBWT
    //map<char, vector<int> > occ_count_before;
    // Preprocess the BWT once to get starts and occ_count_before.
    // For each pattern, we will then use these precomputed values and
    // spend only O(|pattern|) to find all occurrences of the pattern
    // in the text instead of O(|pattern| + |text|).
    PreprocessBWT(bwt, firstocc, arr);
    for (int pi = 0; pi < pattern_count; ++pi) {
        string pattern;
        cin >> pattern;
        int occ_count = CountOccurrences(pattern, bwt, firstocc, arr);
        printf("%d ", occ_count);
    }
    printf("\n");
    return 0;
}
