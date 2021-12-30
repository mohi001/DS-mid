cmake_minimum_required(VERSION 3.0.0)
project(DS-mid VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(DS-mid  main.cpp in_to_postfix.cpp in_to_prefix.cpp post_to_in.cpp post_to_prefix.cpp pre_to_infix.cpp pre_to_post.cpp validate.cpp Stack.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
