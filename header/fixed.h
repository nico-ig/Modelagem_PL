#ifndef __FIXED__
#define __FIXED__

#include <vector>
#include <string>

#define PRECISION 100
#define PRECISION_DECIMAL_PLACE 2
#define PRINT_FIXED(n) (std::to_string((n)/PRECISION)+"."+std::to_string((n)%PRECISION))
#define PARSE_FIXED(n) ((n)/PRECISION + (n)%PRECISION)

long long parse_string_to_longlong(std::vector<std::string>& input);

std::vector<long long> parse_vector_of_fixed(std::vector<std::string>& input, long long size);

long long parse_string_to_fixed(std::vector<std::string>& input);
#endif
