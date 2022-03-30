## Task 1.1

Write a simple program, where you create one child process.

Parent proces should write a "I am a parent" message, while your child process should write "I am  a child".

 - man 2 fork


## Task 1.2

Please extend last program - make both processes display their process ID (PID) and their parent's PID.

 - man 2 getpid
 - man 2 getppid


## Task 1.3

Modify last program, so that it creates not one but 5 child processes


## Task 1.4

Go back to the code from Task 1.2 (with one child process)  
Please check, what happens when

1. parent finishes execution before its child  
2. child finishes execution before its parent

Use sleep(..) function to force a delay.  
You can check process state using  "ps -f \<pid\>" command


## Task 1.5

The main program creates one child process. The offspring is supposed to write numbers from 1 to 10 (every second) to the screen.  
The parent process should wait for the child process to finish and then output the message "END OF WORK"

 - man 3 sleep
 - man 2 wait


## Task 1.6

The main program generates two random integers:  
a - from the range 0...10  
b - from the range 20...30

Then it creates a child process.

The child process calculates the sum of a+b values and returns it as its exit status.

The parent process waits for the child process to finish calculating, receives its execution status, and displays returned sum.

 - man 2 exit
 - man 2 wait

Please read the description of WEXITSTATUS macro carefully as there are some important limitations on what kind of data you can pass between processes using this method!


## Task 1.7

The main program allocates a 1000000-element integer array on the heap (free-store)  
Then it fills it with random values from the range **0....100**

After preparing the array it creates 10 child processes. The task of each of the child processes is to determine the average value of the array fragment (rounded to the nearest integer):  
descendant 0 - from index 0 to 99999  
descendant 1 - from index 100000 to 199999  
descendant 2 - from index 200000 to 299999  
...

The parent process waits for the descendant processes to complete their calculations and then determines the average value of the array elements based on the obtained partial averages.


## Task 1.8

The main program allocates a 1000000-element array of floating point numbers on the heap.  
Then it fills it with random values from the range **-1....1**

After preparing the array it creates 10 child processes. The task of each of the child processes is to determine the sum of the elements of the array fragment:  
descendant 0 - from index 0 to 99999  
descendant 1 - from index 100000 to 199999  
descendant 2 - from index 200000 to 299999  
...
**After determining the sum the child processes write it to the file named "sum/<PID/>.txt" and finish their work.**

The parent process waits for the completion of calculations by the child processes and then determines the average value of the array elements based on the contents of files with partial results.
