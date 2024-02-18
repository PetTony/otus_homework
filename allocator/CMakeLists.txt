add_executable(allocator src/main.cxx)
target_include_directories(allocator PUBLIC include)

target_include_directories(allocator PUBLIC include "${CMAKE_BINARY_DIR}")

target_warning_enable(allocator)

install(TARGETS allocator RUNTIME DESTINATION bin)
