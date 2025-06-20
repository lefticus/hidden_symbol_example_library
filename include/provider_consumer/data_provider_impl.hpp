// this file to be included by anyone who actually needs the 
// data as a constant expression

#ifndef LEFTICUS_HIDDEN_SYMBOLS_DATA_PROVIDER_IMPL_HPP
#define LEFTICUS_HIDDEN_SYMBOLS_DATA_PROVIDER_IMPL_HPP

#include <string_view>
#include <span>

namespace lefticus {
consteval auto make_data()
{
  std::array<std::string_view, 255> data{};
  data[1] = "Hello World";
  data[2] = "Strings of data";
  data[100] = "version 2.0";
  return data;
}

// I would like to make this consteval, but a bug
// in clang makes it so that static constexpr data
// in a consteval function is removed, which is
// very, very, very bad.
constexpr const auto &get_data()
{
  static constexpr auto data = make_data();
  return data;
}
}

#endif

