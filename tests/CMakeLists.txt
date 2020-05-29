add_executable(expression_inserter_test vector_test.cc)

target_compile_options(expression_inserter_test PRIVATE -O0 -g --coverage)

add_library(doctest INTERFACE)

target_include_directories(doctest
                           INTERFACE ${PROJECT_SOURCE_DIR}/external/doctest)

target_link_libraries(expression_inserter_test PRIVATE doctest --coverage)

add_test(NAME expression_inserter_test
         COMMAND $<TARGET_FILE:expression_inserter_test> --success)
