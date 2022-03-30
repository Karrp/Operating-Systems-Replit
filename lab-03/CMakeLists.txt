# gather all cpp files and build them as one executable
# NOTICE: requires cmake 3.11 or newer !
# file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp )
# add_executable(foo ${SOURCES})

# include files are in separate directory
# target_include_directories(foo PRIVATE includes)

add_executable(f1 f1.cpp)
add_custom_command(
        TARGET f1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_BINARY_DIR}/f1
                ${CMAKE_CURRENT_BINARY_DIR}/../main)