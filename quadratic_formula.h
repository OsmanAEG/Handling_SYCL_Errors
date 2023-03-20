#include <math.h>
#include <assert.h>
#include <tuple>
#include <stdexcept>
#include <utility>

template<typename Scalar_type>
auto quadratic_formula(Scalar_type a, Scalar_type b, Scalar_type c){
  const auto descriminant = b*b - 4.0*a*c;

  if(descriminant < 0) throw std::runtime_error("Negative Descriminant");

  const auto denominator = 2.0*a;

  const auto x1 = (-b + sqrt(descriminant))/(2.0*a);
  const auto x2 = (-b - sqrt(descriminant))/(2.0*a);

  return std::make_pair(x1, x2);
}