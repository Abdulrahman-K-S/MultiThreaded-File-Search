# <p align='center'> MultiThreaded-File-Search</p>

A multi-threaded program to search for a specific keyword in multiple files concurrently using pthreads for thread management.

### Input
The program accepts the following inputs:
- Keyword to search for (which is of type string).
- List of files to search in.

### How to run the program
To run this program all you need to do is write this line in the terminal to compile the C file
```terminal
gcc main.c search_file.c multithread_search.h -o search -lpthread
```
And then to use the executable you'll need to write it in this format
```terminal
./search <keyword> <file1> <file2> ... <fileN>
```

At the moment I have limited the file numbers to 100 but feel free to increase or decrease this number

### Examples

#### Example 1
```
root@:/os# ./search "was" file0 file1 file2 file3 file4 file5
(Thread #139931640870656)       Keyword 'was' found in file 'file0' at line '1': Waiting and watching. It was all she had done for the past weeks.
 
(Thread #139931632477952)       Keyword 'was' found in file 'file1' at line '1': It was cloudy outside but not really raining.
 
(Thread #139931632477952)       Keyword 'was' found in file 'file1' at line '2': There was a light sprinkle at most and there certainly wasn't a
 
(Thread #139931624085248)       Keyword 'was' found in file 'file2' at line '1': She looked at her little girl who was about to
 
(Thread #139931624085248)       Keyword 'was' found in file 'file2' at line '6': She was no longer a little girl and she stood there speechless
 
(Thread #139931607299840)       Keyword 'was' found in file 'file4' at line '3': there was nothing that she could see that was
 
(Thread #139931607299840)       Keyword 'was' found in file 'file4' at line '5': to last year, she couldn't see how anything was
 
(Thread #139931598907136)       Keyword 'was' found in file 'file5' at line '2': panic. There was still time to
 
(Thread #139931598907136)       Keyword 'was' found in file 'file5' at line '4': she was telling himself. The reality was that it was time to panic and
```

#### Example 2
```
root@:/os# ./search "a" file0 file1 file2 file3 file4 file5
(Thread #140132964132608)       Keyword 'a' found in file 'file0' at line '2': When you’re locked in a room with nothing but food and drink, that’s about all you can do anyway.
 
(Thread #140132964132608)       Keyword 'a' found in file 'file0' at line '5': She thought she could escape through it but three stories is a bit far down. 
(Thread #140132955739904)       Keyword 'a' found in file 'file1' at line '2': There was a light sprinkle at most and there certainly wasn't a
 
(Thread #140132947347200)       Keyword 'a' found in file 'file2' at line '2': become a teen. She tried to think back to when
 
(Thread #140132947347200)       Keyword 'a' found in file 'file2' at line '4': the exact moment when she had become a
 
(Thread #140132947347200)       Keyword 'a' found in file 'file2' at line '6': She was no longer a little girl and she stood there speechless
 
(Thread #140132938954496)       Keyword 'a' found in file 'file3' at line '2': and took a sip of the drink. He had tasted this
```

### Authors
Abdulrahman Khaled (AK-Salah@outlook.com)