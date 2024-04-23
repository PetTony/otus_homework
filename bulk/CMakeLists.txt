add_executable(bulk src/main.cxx src/bulk.cxx)
target_include_directories(bulk PUBLIC include)

target_include_directories(bulk PUBLIC include "${CMAKE_BINARY_DIR}")

target_warning_enable(bulk)

install(TARGETS bulk RUNTIME DESTINATION bin)
