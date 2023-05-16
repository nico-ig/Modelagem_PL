#include <string>
#include <sstream>
#include <iostream>

#include "fixed.h"
#include "modeling.h"

long long N, M;
std::vector<long long> V, P, Q;
std::vector<std::vector<long long>> C;

bool is_number(std::string s) {
  return s.find("\n") == std::string::npos &&
         s.find("\t") == std::string::npos &&
         s.find(" ")  == std::string::npos;
}

long long calc_product_cost(long long i) {
    long long c = 0;
    for ( long long j = 0; j < M; j++ ) {
      c += MULTIPLY_FIXED(C[i][j] * P[j]);
    }

  return c;
}

long long calc_profit(long long i) {
  return V[i] - calc_product_cost(i);
}

void parse_products_sell_values(std::vector<std::string>& inputs) {
  std::vector<long long> parsed {parse_vector_of_fixed(inputs, N)};
  copy(parsed.begin(), parsed.end(), V.begin());
}

void parse_products_price_and_restriction(std::vector<std::string>& inputs) {
  for ( long long i = 0; i < M; i++ ) {
    P[i] = parse_string_to_fixed(inputs);
    Q[i] = parse_string_to_fixed(inputs);
  }
}

void parse_products_composition(std::vector<std::string>& inputs) {
  for ( std::vector<long long>& vc : C ) {
    std::vector<long long> parsed {parse_vector_of_fixed(inputs, M)};
    vc.resize(parsed.size());
    copy(parsed.begin(), parsed.end(), vc.begin());
  }
}

void parse_inputs(std::vector<std::string> inputs) {
  N = parse_string_to_longlong(inputs); 
  M = parse_string_to_longlong(inputs); 

  V.resize(N); P.resize(M); Q.resize(M); C.resize(N);
  parse_products_sell_values(inputs);
  parse_products_price_and_restriction(inputs);
  parse_products_composition(inputs);
}

int read_inputs() {
  long long n, m;
  std::cin >> n >> m;
  if ( n <= 0 || m <= 0 ) { return READING_ERROR; }
   
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
  
  parse_inputs(inputs);
  return READING_SUCCESS;
}

void print_readings() {
  std::cout << N << " " << M << "\n";

  for ( long long vi : V ) { 
    print_fixed(vi);
    std::cout << " "; 
  }
  std::cout << "\n";

  for ( long long j = 0; j < M; j++ ) { 
    print_fixed(P[j]);
    std::cout << " " ;
    print_fixed(Q[j]);
    std::cout << "\n"; 
  }

  for ( auto vc : C ) { 
    for ( auto cij : vc ) { 
      print_fixed(cij);
      std::cout << " ";
    } 
    std::cout << "\n";
  }
}

void print_object_function() {
  std::string signal;
  long long profit = calc_profit(0);

  if ( profit < 0 ) { profit = -profit; signal = "-"; } 
  else { signal = ""; }
  std::cout << "max: " << signal;
  print_fixed(profit);
  std::cout << "x" << std::to_string(1);

  for ( long long i = 1; i < N; i++ ) {
    profit = calc_profit(i); 
    if ( profit < 0 ) { profit = -profit; signal = " - "; } 
    else { signal = " + "; }
    std::cout << signal; 
    print_fixed(profit); 
    std::cout << "x" << std::to_string(i+1); 
  } 
    
  std::cout << ";\n";
}

void print_restrictions() {
  std::string signal;

  for ( long long j = 0; j < M; j++ ) {
    long long c = C[0][j];
    if ( c < 0 ) { c = -c; signal = "-"; }
    else { signal = ""; }
    std::cout << signal; 
    print_fixed(c); 
    std::cout << "x" << std::to_string(1);

    for ( long long i = 1; i < N; i++ ) {
       c = C[i][j];
       if ( c < 0 ) { c = -c; signal = " - "; }
       else { signal = " + "; }
      std::cout << signal; 
      print_fixed(c); 
      std::cout << "x" << std::to_string(i+1);    
    }
    
    long long q = Q[j];
    if ( q < 0 ) { q = -q; signal = "-"; }
    else { signal = ""; }
    std::cout << " < " << signal; 
    print_fixed(q);
    std::cout << ";\n";
  }
}

