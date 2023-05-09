#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using nfixed = pair<ll, ull>;

ll N, M;
vector<nfixed> V, P, Q;
vector<vector<nfixed>> C;

void print_frac(ull n) {
  cout << "FRAC: " << n << "\n";
  for ( ull byte_cnt = 0; byte_cnt < n/8; byte_cnt++ ) {
    ull byte = (n & (0xF << (8*byte_cnt)));
    cout << byte;
  }
  cout << "\n";
}

void print_fixed(const nfixed n) {
  cout << n.first << "."; print_frac(n.second);
}

void print_readings() {
  cout << N << " " << M << "\n";

  for ( auto vi : V ) { 
    print_fixed(vi); cout << " "; 
  }
  cout << "\n";

  for ( ll j = 0; j < M; j++ ) { 
    print_fixed(P[j]); cout << " " ;
    print_fixed(Q[j]); cout << "\n"; 
  }

  for ( auto vc : C ) { 
    for ( auto cij : vc ) { 
      print_fixed(cij); cout << " "; 
    } 
    cout << "\n";
  }
}

vector<string> read_inputs() {
  ll n, m;
  cin >> n >> m;
   
  vector<string> inputs((n+2)*(m+1));

  inputs[0] = to_string(n);
  inputs[1] = to_string(m);

  string line;
  int i = 2;
  while ( getline(cin, line) ) {
    stringstream ss(line);
    string val;
    while( getline(ss, val, ' ') ) { inputs[i++] = val; }
  } 
  
  return inputs;
}

ll parse_string_to_ll(vector<string>& input) {
  ll res = 0;
  string ss = input[0];
  for ( char c : ss ) { res = res * 10 + (c - '0'); }
  
  input.erase(input.begin());
  return res;
}

ull parse_string_to_frac(vector<string>& input) {
  ull res = 0;
  string ss = input[0];
  for ( ll i = ss.size() - 1; i >= 0; i-- ) {
    res = res * 10 + (ss[i] - '0');
  }

  input.erase(input.begin());
  return res;
}

nfixed parse_string_to_fixed(vector<string>& input) {
  nfixed res;

  size_t dot_pos = input[0].find('.');

  vector<string> int_part{input[0].substr(0, dot_pos)};
  res.first = parse_string_to_ll(int_part);

  if ( dot_pos != string::npos ) {
    vector<string> frac_part{input[0].substr(dot_pos + 1)};
    res.second = parse_string_to_frac(frac_part); 
  } 

  else {
    res.second = 0;
  }

  input.erase(input.begin());
  return res;
}

vector<nfixed> parse_vector_of_fixed(vector<string>& input, ll size) {
  vector<nfixed> v(size);
  for ( ll i = 0; i < size; i++ ) { v[i] = parse_string_to_fixed(input); }

  return v;
}

void parse_products_sell_values(vector<string>& inputs) {
  vector<nfixed> parsed {parse_vector_of_fixed(inputs, N)};
  copy(parsed.begin(), parsed.end(), V.begin());
}

void parse_products_price_and_restriction(vector<string>& inputs) {
  for ( ll i = 0; i < M; i++ ) {
    P[i] = parse_string_to_fixed(inputs);
    Q[i] = parse_string_to_fixed(inputs);
  }
}

void parse_products_composition(vector<string>& inputs) {
  for ( vector<nfixed>& vc : C ) {
    vector<nfixed> parsed {parse_vector_of_fixed(inputs, M)};
    vc.resize(parsed.size());
    copy(parsed.begin(), parsed.end(), vc.begin());
  }
}

void parse_inputs(vector<string> inputs) {

  N = parse_string_to_ll(inputs); 
  M = parse_string_to_ll(inputs); 

  V.resize(N); P.resize(M); Q.resize(M); C.resize(N);
  parse_products_sell_values(inputs);
  parse_products_price_and_restriction(inputs);
  parse_products_composition(inputs);
}

int main() {
  parse_inputs(read_inputs());
  print_frac(16);
//  print_readings();
}
