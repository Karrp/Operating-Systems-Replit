## Task 2.1

Perform basic test with pipe in single process

1) create a pipe

2) write some data

3) read it back

4) verify

man 2 pipe  
man 2 read  
man 2 write  


## Task 2.2

As you remember - fork() creates an almost identical copy of the parent process. Interestingly, this copy "inherits" parent's process open file descriptors

```
The child inherits copies of the parent's set of open file descriptors. Each file descriptor in the child refers to the same open file description  
(see open(2)) as the corresponding file descriptor in the parent. This means that the two file descriptors share open file status flags, file offset,  
and signal-driven I/O attributes (see the description of F_SETOWN and F_SETSIG in fcntl(2)).
```

This means that if you use pipe before fork, you get a pipeline that you can write to in one process and read in another

Please modify your program from Task 2.1 so that the parent writes to the pipe and the child reads and displays received data


## Task 2.3

Usually - for added security - you close unnecessary ends of the pipe after the fork. That is, if the pipeline is used to send data from the parent to the child, then the parent closes its 'reading' endpoint, and the child closes its writing side.

If we want two-way communication, we create two pipes (and close their ends accordingly)

Task:  
 - Create a simple "echo server"

 - The child in an infinite loop:
   - receives data from the parent (line of text, you can assume it is not longer than 8000 characters)
   - converts all lowercase letters into uppercase (you can use the toupper function)
   - sends the result back to the parent

In the parent process, test sending several texts to the child, read and display the answers


## Task 2.4

Modify task *1.8* to use pipes to pass return values from child processes to their parent.

You may want to create a separate pipe for each child (or deal with buffering issues...)