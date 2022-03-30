cmake_minimum_required (VERSION 3.11)
project (main CXX C)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)

SET(CMAKE_CXX_COMPILER "clang++") # comment in Clion
SET(CMAKE_C_COMPILER "clang") # comment in Clion

# I am not sure WHY this is in an example repl.it CMakeLists.txt template...
SET(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES  ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
SET(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# these should be specified at target level, but lets start with global project settings
# we ALWAYS want these warnings enabled
add_compile_options(-Wall -Wextra)

# not a bad idea for strict standard compliance
add_compile_options(-pedantic)

# change some warnings into errors
# missing return in non-void function: “control reaches end of non-void function"
add_compile_options(-Werror=return-type)

# detect some trivial array-bounds errors in code (only compile-time !!)
add_compile_options(-Werror=array-bounds)

# misleading parentheses
# read here: https://www.ibm.com/docs/en/ztpf/1.1.0.14?topic=warnings-parentheses
add_compile_options(-Werror=parentheses)

# VLA is a non-standard feature of some c++ compilers - this prevents its usage 
add_compile_options(-Werror=vla)

# this will help you detect SOME of the runtime memory access violations
# WARNING - BOTH compile and link options are required !
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Each time we start a new topic I will ask you to do the following
# 1. create a new subdirectory, eg. lab-02
# 2. populate it with essential files (CMakeLists.txt !)
# 3. include it here with add_subdirectory command
#
# I have prepared lab-01 and lab-02 for you with some very basic examples
# Feel free to adjust them as necessary
add_subdirectory(lab-01)
add_subdirectory(lab-02)

# don't touch ;)
add_custom_target(
	copy-compile-commands ALL
	${CMAKE_COMMAND} -E copy_if_different
	${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_CURRENT_LIST_DIR}
)


