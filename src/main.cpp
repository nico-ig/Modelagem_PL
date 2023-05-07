#include <vector>
#include <iostream>

using namespace std;
using ull = unsigned long long;
using nfloat = pair<ull, ull>;

int main() {
  ull n, m;
  cin >> n >> m;

  vector<ull> v(n);
  for ( auto& vi : v ) { cin >> vi; }

  vector<ull> p(m), q(m);
  for ( size_t j = 0; j < m; j++ ) { cin >> p[j] >> q[j]; }

  vector<vector<nfloat>> c(n, vector<nfloat>(m));
  char dot;
  for ( auto& vc : c ) { 
    for ( auto& cij : vc ) { 
      cin >> cij.first >> dot >> cij.second; 
    } 
  }
  
  cout << n << " " << m << "\n";
  for ( auto vi : v ) { cout << vi << " "; } cout << "\n";
  for ( size_t j = 0; j < m; j++ ) { cout << p[j] << " " << q[j]; cout << "\n"; }
  for ( auto vc : c ) { 
    for ( auto cij : vc ) { 
      cout << cij.first << "." << cij.second << " "; 
    } 
    cout << "\n";
  }

}
