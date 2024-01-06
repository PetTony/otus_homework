configure_file(include/version.h.in "${CMAKE_BINARY_DIR}/version.h")

add_executable(helloworld_cli src/main.cpp)
target_include_directories(helloworld_cli PUBLIC include)
target_link_libraries(helloworld_cli PRIVATE helloworld)

add_library(helloworld src/lib.cpp)
target_include_directories(helloworld PUBLIC include "${CMAKE_BINARY_DIR}")

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

target_warning_enable(helloworld)
target_warning_enable(helloworld_cli)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
