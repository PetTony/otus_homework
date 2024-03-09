add_executable(print_ip src/main.cxx)
target_include_directories(print_ip PUBLIC include)

target_include_directories(print_ip PUBLIC include "${CMAKE_BINARY_DIR}")

target_warning_enable(print_ip)

install(TARGETS print_ip RUNTIME DESTINATION bin)
