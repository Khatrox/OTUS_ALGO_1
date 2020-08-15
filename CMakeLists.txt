cmake_minimum_required(VERSION 3.14)
project(TestTask)

if(WIN32)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/google_test)

set (TESTS_FOLDER "${CMAKE_SOURCE_DIR}/Tests")
configure_file(test_folder_define.h.in test_folder_define.h)

set (SOURCE ${CMAKE_SOURCE_DIR}/src/)
add_executable(TestTask 
		${SOURCE}main.cpp
		${SOURCE}TestInputOutputTaker.h
		${SOURCE}TestInputOutputTaker.cpp
		${SOURCE}Task.h
		${SOURCE}TaskFactory.h
		${SOURCE}FirstAssignmentFactory.h
		${SOURCE}FirstAssignmentFactory.cpp
		${SOURCE}exist_file.h
		)

set_target_properties(TestTask
                      PROPERTIES
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED ON
                     )

target_include_directories(TestTask
                           PRIVATE
                           ${SOURCE}
                           ${CMAKE_SOURCE_DIR}/google_test
			    ${CMAKE_BINARY_DIR}
                            )

target_link_libraries(TestTask
                      PRIVATE
                      gtest
                      gtest_main
                      gmpxx
                      gmp
                      )
