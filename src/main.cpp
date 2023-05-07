#include <vector>
#include <iostream>

using namespace std;
using ull = unsigned long long;
using nfloat = pair<ull, ull>;

vector<ull> V, P, Q;
vector<vector<nfloat>> C;

void read_products_sell_value(ull n) { 
  vector<ull> v(n);
  for ( auto& vi : v ) { cin >> vi; } 
  V = v;
}

void read_composts_cost_and_limit(ull m) {
  vector<ull> p(m), q(m);
  for ( size_t j = 0; j < m; j++ ) { cin >> p[j] >> q[j]; }
  P = p; 
  Q = q;
}

void read_products(ull n, ull m) {
  vector<vector<nfloat>> c(n, vector<nfloat>(m));
  char dot;
  for ( auto& vc : c ) { 
    for ( auto& cij : vc ) { 
      cin >> cij.first >> dot >> cij.second; 
    } 
  }
  
  C = c;
}

void print_readings(ull n, ull m) {
  cout << n << " " << m << "\n";
  for ( auto vi : V ) { cout << vi << " "; } cout << "\n";
  for ( size_t j = 0; j < m; j++ ) { cout << P[j] << " " << Q[j]; cout << "\n"; }
  for ( auto vc : C ) { 
    for ( auto cij : vc ) { 
      cout << cij.first << "." << cij.second << " "; 
    } 
    cout << "\n";
  }
}

int main() {
  ull n, m;
  cin >> n >> m;

  read_products_sell_value(n);
  read_composts_cost_and_limit(m);
  read_products(n, m);

  print_readings(n, m);
}
