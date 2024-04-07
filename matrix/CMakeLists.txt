add_executable(matrix src/main.cxx)
target_include_directories(matrix PUBLIC include)

target_include_directories(matrix PUBLIC include "${CMAKE_BINARY_DIR}")

target_warning_enable(matrix)

install(TARGETS matrix RUNTIME DESTINATION bin)
