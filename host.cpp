#include "quadratic_formula.h"

int main(){
  // defining quadratic properties
  const double a = 3.0;
  const double b = 2.1;
  const double c = 8.2;

  auto roots = quadratic_formula(a, b, c);

  auto x1 = roots.first;
  auto x2 = roots.second;
}