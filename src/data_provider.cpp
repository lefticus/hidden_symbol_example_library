#include <string_view>
#include <span>

#include "provider_consumer/data_provider_impl.hpp"

namespace lefticus {
std::span<const std::string_view, 255> get_data_view()
{
  static constexpr auto &data = get_data();
  return data;
}

}
