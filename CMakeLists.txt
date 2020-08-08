cmake_minimum_required(VERSION 3.14)
project(TestTask)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/google_test)

add_executable(TestTask ${CMAKE_SOURCE_DIR}/src)

set_target_properties(TestTask
                      PROPERTIES
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON
                     )

target_include_directories(TestTask
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}/google_test
                            )

target_link_libraries(TestTask
                      PRIVATE
                      gtest
                      gtest_main
                      )
