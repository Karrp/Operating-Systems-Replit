#include <iostream>


#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

void hello()
{
   std::cout << "Hello world!" << std::endl; 

    // this is just to make build fail without adding librt !
    // comment out target_link_libraries line in CMakeLists.txt to test it
    shm_unlink("/foo");
}
