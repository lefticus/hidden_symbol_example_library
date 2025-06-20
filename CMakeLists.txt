cmake_minimum_required(VERSION 3.24)
project(hidden_symbol_example_library)

# Error if not supported with this simple command
include(CheckIPOSupported)
check_ipo_supported()

add_library(compiler_options INTERFACE)
target_compile_features(compiler_options INTERFACE cxx_std_23)

add_library(provider_consumer SHARED src/data_provider.cpp src/data_consumer.cpp)
target_link_libraries(provider_consumer PRIVATE compiler_options)
set_target_properties(provider_consumer PROPERTIES CXX_VISIBILITY_PRESET hidden
                                                   INTERPROCEDURAL_OPTIMIZATION TRUE)

target_include_directories(provider_consumer PUBLIC "${CMAKE_BINARY_DIR}/generated_includes")
target_include_directories(provider_consumer PUBLIC "include")


include(GenerateExportHeader)

# Putting in subfolder for consistency with public and private consumers, keeping .h file name because 
# it is a C header
generate_export_header(provider_consumer EXPORT_FILE_NAME generated_includes/provider_consumer_export.h)


add_executable(test test/test.cpp)
target_link_libraries(test provider_consumer compiler_options)

