#include <vector>
#include <sstream>
#include <iostream>

#include "modeling.h"

using namespace std;

int main() {
  if ( read_inputs() == READING_ERROR ) { return READING_ERROR; } 
  //print_readings();
  print_object_function();
  print_restrictions();
}
