add_executable(ip_filter src/ip_filter.cxx src/ip.cpp)
target_include_directories(ip_filter PUBLIC include)

target_include_directories(ip_filter PUBLIC include "${CMAKE_BINARY_DIR}")

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

target_warning_enable(ip_filter)

install(TARGETS ip_filter RUNTIME DESTINATION bin)
