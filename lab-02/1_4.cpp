//#include "f2.h"
#include <iostream>
#include <unistd.h>

using namespace std;

// declaration tells us
// - function name
// - function arguments
// - function return type

// definition additionally provides function body


int main() 
{ 
  int pidOld = getpid();
  int parent;

  bool fiveKids = false; //true;
  
  if(fiveKids)
    //5 kids
    for(int i=0; i<5; i++)
    {
      int ppid = getppid();
  
      if (ppid!=pidOld)
        parent = fork();
    }
  else //one kid
    parent = fork();

  int pid = getpid();
  int ppid = getppid();

  //sleep(10);
  
  if (parent>0) //parent
  {
    cout << "I am a parent - ";
    cout <<"my: "<<pid<<" & parent: "<<ppid<<endl;
    //sleep(10);
    cout<< "parent end\n";
  }
  else if(!parent) //not parent
  {
    cout << "I am  a child - ";
    cout <<"my: "<<pid<<" & parent: "<<ppid<<endl;
    sleep(10);
    cout<< "child end\n";
  }
  else
    cout << "Error in fork\n";

  //If child finish before parent - child's waiting until parent end his work and will kill his child.
  
  //if paren finish before child - child become an orphant and is adopted by proces with pid 1 (init) and he kills the child when it end his work //aka come from kindergarten

  //cout <<"my: "<<pid<<" & parent: "<<ppid<<endl;

  
}