#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int parent()
{
  // wait for chid extermination
  cout<<"END OF WORK\n";

  return 0;
}

int child()
{
  for(int i=1; i<=10; i++)
  {
    cout<<i<<endl;
    sleep(1);      
  }

  return 0;
}

int main() 
{ 
  srand(time(NULL));
  int a = rand()%11;
  int b = rand()%11+20;

  cout<<a<<":a, b:"<<b<<endl;
  
  int forker = fork();
  
  if (forker>0) //parent
  {
    waitpid(-1, &forker, 0);
    parent();
  }
  else if(!forker) //not parent
  {
    child();
    exit(0);
  }
  else
    cout << "Error in fork\n";

}