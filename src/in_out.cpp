#include <sstream>
#include <iostream>
#include "in_out.h"

ll N, M;
std::vector<ll> V, P, Q;
std::vector<std::vector<ll>> C;

void print_readings() {
  std::cout << N << " " << M << "\n";

  for ( ll vi : V ) { 
    std::cout << PRINT_FIXED(vi) << " "; 
  }
  std::cout << "\n";

  for ( ll j = 0; j < M; j++ ) { 
    std::cout << PRINT_FIXED(P[j]) << " " ;
    std::cout << PRINT_FIXED(Q[j]) << "\n"; 
  }

  for ( auto vc : C ) { 
    for ( auto cij : vc ) { 
      std::cout << PRINT_FIXED(cij) << " "; 
    } 
    std::cout << "\n";
  }
}

bool is_number(std::string s) {
  return s.find("\n") == std::string::npos &&
         s.find("\t") == std::string::npos &&
         s.find(" ")  == std::string::npos;
}

std::vector<std::string> read_inputs() {
  ll n, m;
  std::cin >> n >> m;
   
  std::vector<std::string> inputs((n+2)*(m+1));

  inputs[0] = std::to_string(n);
  inputs[1] = std::to_string(m);

  std::string line;
  int i = 2;
  while ( getline(std::cin, line) ) {
    std::stringstream ss(line);
    std::string val;
    while( ss >> val ) { if ( is_number(val) ) { inputs[i++] = val;} }
  } 
  
  return inputs;
}

ll parse_string_to_ll(std::vector<std::string>& input) {
  ll res = 0;
  std::string ss = input[0];
  for ( char c : ss ) { res = res * 10 + (c - '0'); }
  
  input.erase(input.begin());
  return res;
}

ll parse_string_to_frac(std::vector<std::string>& input) {
  ll res = 0;
  size_t i = 0;
  std::string ss = input[0];

  for ( i = 0; i < ss.size() && i < PRECISION_DECIMAL_PLACE; i++ ) {
    res = res * 10 + (ss[i] - '0');
  }

  i = PRECISION_DECIMAL_PLACE - i;
  while ( i-- > 0 ) {
   res *= 10; 
  }

  input.erase(input.begin());
  return res;
}

ll parse_string_to_fixed(std::vector<std::string>& input) {
  size_t dot_pos = input[0].find('.');

  std::vector<std::string> int_part{input[0].substr(0, dot_pos)};
  ll res = parse_string_to_ll(int_part);
  res *= PRECISION;

  if ( dot_pos != std::string::npos ) {
    std::vector<std::string> frac_part{input[0].substr(dot_pos + 1)};
    res += parse_string_to_frac(frac_part); 
  } 

  input.erase(input.begin());
  return res;
}

std::vector<ll> parse_vector_of_fixed(std::vector<std::string>& input, ll size) {
  std::vector<ll> v(size);
  for ( ll i = 0; i < size; i++ ) { v[i] = parse_string_to_fixed(input); }

  return v;
}

void parse_products_sell_values(std::vector<std::string>& inputs) {
  std::vector<ll> parsed {parse_vector_of_fixed(inputs, N)};
  copy(parsed.begin(), parsed.end(), V.begin());
}

void parse_products_price_and_restriction(std::vector<std::string>& inputs) {
  for ( ll i = 0; i < M; i++ ) {
    P[i] = parse_string_to_fixed(inputs);
    Q[i] = parse_string_to_fixed(inputs);
  }
}

void parse_products_composition(std::vector<std::string>& inputs) {
  for ( std::vector<ll>& vc : C ) {
    std::vector<ll> parsed {parse_vector_of_fixed(inputs, M)};
    vc.resize(parsed.size());
    copy(parsed.begin(), parsed.end(), vc.begin());
  }
}

void parse_inputs(std::vector<std::string> inputs) {

  N = parse_string_to_ll(inputs); 
  M = parse_string_to_ll(inputs); 

  V.resize(N); P.resize(M); Q.resize(M); C.resize(N);
  parse_products_sell_values(inputs);
  parse_products_price_and_restriction(inputs);
  parse_products_composition(inputs);
}
