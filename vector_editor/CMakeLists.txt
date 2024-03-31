add_executable(vector_editor src/main.cxx)
target_include_directories(vector_editor PUBLIC include)

target_include_directories(vector_editor PUBLIC include "${CMAKE_BINARY_DIR}")

target_warning_enable(vector_editor)

install(TARGETS vector_editor RUNTIME DESTINATION bin)
