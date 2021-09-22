
# @file CMakeLists.txt
# 
# CMake files for FSM

# Can be run by any version of CMake >= this
cmake_minimum_required(VERSION 3.19)

# project info
project(FSM)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Source files for the main program fsm
set(SOURCE fsm.cpp)

# fsm application
add_executable(fsm ${SOURCE})

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Demo run command
add_custom_target(run
        COMMENT "Run demo"
        COMMAND time ./fsm "aaabbb"
        DEPENDS fsm
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
