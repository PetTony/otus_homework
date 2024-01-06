function(target_warning_enable TARGET_NAME)
    target_compile_options(${TARGET_NAME} PRIVATE
       $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
       $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
        -Wall 
        -Wextra 
        -Wpedantic 
        -Werror=return-type>
    )   
endfunction(target_warning_enable)