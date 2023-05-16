#include "fixed.h"

long long parse_string_to_longlong(std::vector<std::string>& input) {
  long long res = 0, negative_cnt = 0;
  std::string ss = input[0];
  for ( char c : ss ) { 
    if ( c == '-' ) { negative_cnt++; }
    else { res = res * 10 + (c - '0'); }
  }
  
  input.erase(input.begin());

  return negative_cnt % 2 == 0 ? res : -res; 
}

long long parse_string_to_decimal(std::vector<std::string>& input) {
  long long res = 0;
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

long long parse_string_to_fixed(std::vector<std::string>& input) {
  size_t dot_pos = input[0].find('.');

  std::vector<std::string> int_part{input[0].substr(0, dot_pos)};
  long long res = parse_string_to_longlong(int_part);
  res *= PRECISION;

  if ( dot_pos != std::string::npos ) {
    std::vector<std::string> frac_part{input[0].substr(dot_pos + 1)};
    if ( res >= 0 ) { res += parse_string_to_decimal(frac_part); }
    else { res -= parse_string_to_decimal(frac_part); }
  } 

  input.erase(input.begin());
  return res;
}

std::vector<long long> parse_vector_of_fixed(std::vector<std::string>& input, long long size) {
  std::vector<long long> v(size);
  for ( long long i = 0; i < size; i++ ) { v[i] = parse_string_to_fixed(input); }

  return v;
}
