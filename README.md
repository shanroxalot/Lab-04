# Lab-04: File Input/Output Functions

## Name: 

## Honor Code:

I, _______, declare that I have completed this assignment completely and entirely on my own, without any unathorized consultation from others or unathorized access to online websites. I have read the UAB Academic Honor Code and understand that any breach of the UAB Academic Honor Code may result in severe penalties.

Student Signature/Initials: ____________

Date: ____________

## Assignment:

Write a program in C that concatenates the contents of one file to another file.

- Do not use the fputs() or fputc() functions. You should use a combination of the lseek() and the open() functions.

- The names of the files should be provided as command-line arguments.

- The contents of the second file should be concatenated to the contents of the first file.

- **Check if the names of the file are the same (e.g. './lab04 file1 file1), if so print an error message and then exit.**

After execution, 

- The first file should contain it's orginal content and also the contents of the second file. 

- The second file remains unmodified.

## Example:

> $ cat file1.txt
>> Hello World! This is file one.
>
> $ cat file2.txt
>> Hello World! This is file two.
>
> $ ./lab04 file1.txt file2.txt
>
>
> $ cat file1.txt
>> Hello World! This is file one.
>>
>> Hello World! This is file two.
>
> $ cat file2.txt
>> Hello World! This is file two.
