#include <iostream>
#include <vector>
using namespace std;
class Solver {
	string s;
    vector <long long> v1 ;
    vector <long long > v2 ;
    vector <long long > x1 ;
    vector <long long > x2 ;
    long long p = 1e9 +7 ,m=1e9+9;
public:	
	Solver(string s) : s(s) {
        x1.resize(s.size()+1);
        v1.resize(s.size()+1);
        x2.resize(s.size()+1);
        v2.resize(s.size()+1);
       /* x1.push_back(1);
        x2.push_back(1);
        v1.push_back(0);
        v2.push_back(0);*/
        x1[0] = 1 ;
        x2[0] = 1 ;
        v1[0] = 0 ;
        v2[0] = 0 ;
        for(int i=0 ;i<s.size() ;i++){
            /*v1.push_back((x1[i]*s[i] + v1[i])%p);
            v2.push_back((x2[i]*s[i] + v2[i])%m);
            x1.push_back((x1[i]*34)%p);
            x2.push_back((x2[i]*34)%m);*/
            int j= i+1 ;
            v1[j] = (x1[i]*s[i] + v1[i])%p;
            v2[j] = (x2[i]*s[i] + v2[i])%m;
            x1 [j] = (x1[i]*34)%p;
            x2 [j] = (x2[i]*34)%m;
        }
	}
	bool ask(int a, int b, int l) {
	    //if(a>b)swap(a,b);
	    long  long d1 = v1[a+l] - v1[a]+p, f1 = v1[b+l] - v1[b]+p;
        long long  d2 = v2[a+l] - v2[a] +m, f2 = v2[b+l] - v2[b] +m;
       // if(d1<0 )d1  = (d1+p)%p;
       // if(f1<0 )f1  = (f1+p)%p;
       /*
        if(d2<0 )d2  = (d2+m)%m;
        if(f2<0 )f2  = (f2+m)%m;
*/      if((d1*x1[max(b-a,0)])%p == ((f1*x1[max(a-b,0)])%p) && (d2*x2[max(b-a,0)])%m == ((f2*x2[max(a-b,0)])%m) )
	        //return s.substr(a, l) == s.substr(b, l);
    return true ;
	    return false ;
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr); cout.tie(nullptr);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes" : "No") << endl;
		//cout << (s.substr(a, l) == s.substr(b, l)) << endl;
	}
}
