add_executable( mycp mycp.cpp )

# use add_executable for each program you want to build
add_executable( hello hello.cpp )

# we can build both C and C++ files
add_executable( world world.c )

# you may list multiple source files for one executable
# NOTICE: you don't need to add header files here, but 
#         some IDEs may need them to work correctly (eg: CLion)
add_executable( large part1.cpp part2.cpp part2.h )

# IF you need to link a target with some non-standard library, use
target_link_libraries ( large rt )


# probably bad idea... copy selected file as "main" so that we can use "Run" button
# notice - you need to specify both target name and #file location (hello in line 2 and 4) 
#add_custom_command(
#        TARGET mycp POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#                ${CMAKE_CURRENT_BINARY_DIR}/mycp
#                ${CMAKE_CURRENT_BINARY_DIR}/../main)

