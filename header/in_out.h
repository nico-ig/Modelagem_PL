#ifndef __IN_OUT__
#define __IN_OUT__

#include <vector>
#include <string>

#define PRECISION 1000
#define PRECISION_DECIMAL_PLACE 3
#define PRINT_FIXED(n) (std::to_string((n)/PRECISION)+"."+std::to_string((n)%PRECISION))

using ll = long long;

extern ll N, M;
extern std::vector<ll> V, P, Q;
extern std::vector<std::vector<ll>> C;

void print_readings();
std::vector<std::string> read_inputs();
void parse_inputs(std::vector<std::string> inputs);
#endif
