## LAB-01: Little warmup
I'm sure you are all proficient C/C++ programmers, but - just in case you had a long break and forgot some things - lets do a little warmup.

Write your own version of Unix "cp" (copy) command.

As a bare minimum - please write a program that

 - accepts source and destination filenames as its arguments (you DO remember how to use argc and argv ?)
 - makes a copy of indicated file
 - returns 0 on success, any non-zero value on error
 - uses ONLY POSIX I/O functions (open, close, read, write - consult appropriate manuals)

**NOTICE:** Do not assume, that you can read entire file into memory. Please read manuals carefully - pay attention to each function's return value!


I'm sure this task will prove to be to easy to some of you - in this case you can extend your program - for example you can add features to allow:

 - copy source_file dest_dir  (copy source file to the indicated directory, keeping its name)
 - copy file1 file2 file3 dest_dir (copy files file1...file3 into destination directory)
 - copy file while preserving as many of its attributes as possible (permissions, owner, group, etc.)
