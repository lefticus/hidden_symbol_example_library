#include "provider_consumer/data_consumer.hpp"
#include "provider_consumer/data_provider.hpp"

#include <cstdio>

namespace lefticus {
void consume() {
  const auto data = get_data_view();

  std::puts(data[100].data());
  std::puts(data[1].data());
}
}
