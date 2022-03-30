#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024

using namespace std;

int main(int argc, char **argv) 
{
    // check argc
   if(argc != 3)
   {
     cout << "Wrong number of arguments" << endl;
      return 1;
   }
    
    // display all elements in argv
  for(int i=0; i<argc; i++)
  {
    cout << "argv[" << i << "] = " << argv[i] << endl;
  }
    // inside argv[0] is program name and location "build/main"
  
    // later:
  char buf[SIZE];
  
    // use argv[1] as source file name
  char* fNameIn = argv[1];  
    // use argv[2] as destination file name
  char* fNameOut = argv[2]; 
    // open source file for reading in binary mode
  int fIn = open(fNameIn, O_RDONLY, S_IRUSR);
    // open destination file for writing in binary mode
  int fOut = open(fNameOut, O_WRONLY|O_CREAT|O_TRUNC, S_IWUSR);

  int rCheck = SIZE;
  int wCheck = SIZE;

  while(rCheck >= SIZE)
  {
      // read source file in blocks of some size (eg - 1024 bytes)
    rCheck = read(fIn, buf, SIZE);
      //TODO break in reading
    //cout << rCheck << endl;
    
      // write these blocks into destination file
    wCheck = write(fOut, buf, rCheck);
      //TODO break in writing
    //cout << wCheck << endl;

    if (rCheck!=wCheck)
    {
      cout<<"Problem with writing to output file\n";
      break;
    }
  }
  
    // close both files
  if(close(fIn))
    cout<<"Problem with closing input file\n";
  if(close(fOut))
    cout<<"Problem with closing output file\n";


  return 0;

}


// man 2 open