configure_file(include/version.h.in "${CMAKE_BINARY_DIR}/version.h")

add_executable(helloworld_cli src/main.cpp)
add_library(helloworld src/lib.cpp)
add_executable(test_version tests/test_version.cpp)

target_warning_enable(helloworld)
target_warning_enable(helloworld_cli)
target_warning_enable(test_version)

target_include_directories(helloworld
    PUBLIC include "${CMAKE_BINARY_DIR}"
)

target_include_directories(helloworld_cli
    PUBLIC include
)

target_link_libraries(helloworld_cli
    PUBLIC helloworld
)

target_include_directories(test_version
    PUBLIC include
)

target_link_libraries(test_version helloworld gtest gtest_main)

add_test(test_version test_version)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
