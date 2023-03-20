#include "quadratic_formula.h"
#include "error_handling.h"

constexpr int using_sycl = 0;

int main(){
  // defining quadratic properties
  const double a = 3.0;
  const double b = 2.1;
  const double c = 8.2;

  auto roots = quadratic_formula(a, b, c);

  auto x1 = roots.first;
  auto x2 = roots.second;

  output_roots(x1, x2);
}