add_executable(test_ip test_ip.cpp ../src/ip.cpp)
target_include_directories(test_ip PUBLIC ../include)
target_link_libraries(test_ip gtest gtest_main)

add_test(test_ip test_ip)

target_warning_enable(test_ip)
