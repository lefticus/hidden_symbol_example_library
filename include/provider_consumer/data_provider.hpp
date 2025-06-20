// this file is to be included by anyone who
// only needs a view of the data at runtime

#ifndef LEFTICUS_HIDDEN_SYMBOLS_DATA_PROVIDER_HPP
#define LEFTICUS_HIDDEN_SYMBOLS_DATA_PROVIDER_HPP

#include <string_view>
#include <span>

namespace lefticus {
PROVIDER_CONSUMER_EXPORT std::span<const std::string_view, 255> get_data_view();
}

#endif
