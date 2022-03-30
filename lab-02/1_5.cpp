#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() 
{ 
  int parent = fork();
  
  if (parent>0) //parent
  {
    // wait for chid extermination
    waitpid(-1, &parent, 0);
    cout<<"END OF WORK\n";
  }
  else if(!parent) //not parent
  {
    for(int i=1; i<=10; i++)
    {
      cout<<i<<endl;
      sleep(1);      
    }
    exit(0);
  }
  else
    cout << "Error in fork\n";

}