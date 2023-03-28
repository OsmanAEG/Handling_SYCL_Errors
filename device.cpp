#include <CL/sycl.hpp>
#include "quadratic_formula.h"

// prints device name
template<typename Queue_type>
void print_device(Queue_type& Q){
  std::cout << "DEVICE: "
            << Q.get_device().template get_info<sycl::info::device::name>()
            << "\nVENDOR: "
            << Q.get_device().template get_info<sycl::info::device::vendor>()
            << "\n" << std::endl;
}

int main(){
  // defining quadratic properties
  const double a = 3.0;
  const double b = 2.1;
  const double c = 8.2;

  sycl::buffer<double> buffer_roots{sycl::range{2}};

  // establishing gpu for device queue
  sycl::queue Q{sycl::gpu_selector_v};
  print_device(Q);

  Q.submit([&](sycl::handler &h){
    sycl::accessor access_roots{buffer_roots, h, sycl::write_only, sycl::no_init};
    h.single_task([=](){
      auto roots = quadratic_formula(a, b, c);
      access_roots[0] = roots.first;
      access_roots[1] = roots.second;
    });
  });

  sycl::host_accessor host_roots{buffer_roots};

  const auto x1 = host_roots[0];
  const auto x2 = host_roots[1];

  output_roots(x1, x2);
}
