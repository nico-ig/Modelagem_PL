#ifndef __FIXED__
#define __FIXED__

#include <vector>
#include <string>

#define PRECISION 1000
#define PRECISION_DECIMAL_PLACE 3
#define MULTIPLY_FIXED(n) (n/PRECISION)

long long parse_string_to_longlong(std::vector<std::string>& input);
long long parse_string_to_fixed(std::vector<std::string>& input);
std::vector<long long> parse_vector_of_fixed(std::vector<std::string>& input, long long size);
void print_fixed(long long n);

#endif
