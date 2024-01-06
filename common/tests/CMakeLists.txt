add_executable(test_version test_version.cpp)
target_include_directories(test_version PUBLIC ../include)
target_link_libraries(test_version helloworld gtest gtest_main)

add_test(test_version test_version)

target_warning_enable(test_version)
