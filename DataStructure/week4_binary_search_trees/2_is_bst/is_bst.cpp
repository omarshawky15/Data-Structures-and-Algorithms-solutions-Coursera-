#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;
struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void in (vector<int> &res,Node x,const vector<Node>& tree){
    if(x.left!=-1)in(res,tree[x.left],tree);
    res.push_back(x.key);
    if(x.right!=-1)in(res,tree[x.right],tree);
}
vector <int> in_order(const vector<Node>& tree) {
    vector<int> result;
    if(tree.size()>0)in(result,tree[0],tree);
    return result;
}
bool IsBinarySearchTree(const vector<Node>& tree) {
vector<int> res  = in_order(tree);
for(int i=1 ;i<res.size();i++){
    if(res[i-1] >=res[i])return false ;
}
return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree) ){
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
