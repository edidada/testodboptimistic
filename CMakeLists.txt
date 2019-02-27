cmake_minimum_required(VERSION 3.13)
project(testodboptimistic)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDATABASE_MYSQL")

add_executable(testodboptimistic driver.cxx person-odb.cxx)

target_link_libraries(testodboptimistic libodb-mysql.so)

target_link_libraries(testodboptimistic libodb.so)