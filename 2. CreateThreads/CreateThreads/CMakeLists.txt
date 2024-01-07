cmake_minimum_required(VERSION 3.26)
project(Project)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/aa2e91fd6918519dafa3bee4aa706d04857e7d06.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(run_project main.cpp)
add_executable(test_project tests.cpp)

target_link_libraries(test_project gtest_main gmock)

add_test(NAME test_project COMMAND test_project)
