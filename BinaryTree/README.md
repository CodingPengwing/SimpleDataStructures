# Binary Tree #

This library was built with influence from this book:
Moffat, Alistair - Programming, problem solving & abstraction with C-Pearson Education (2002, 2013)  
Chapter 10: A polymorphic tree library.

An implementation of dynamically managed binary trees. 
The creation (memory allocation), insertion, and deletion (free) of the binary tree and 
elements inside the binary tree are abstracted into functions, hiding the details of 
pointer and memory allocation from the user.

This implementation takes away some of the polymorphism in the book's implementation by 
removing many void* pointers, and replacing it with a typed pointer to Data (*Data_t). 
This is to protect the user from the use of void pointers, while still allowing the code 
to be modified to whichever data type is required for the Tree (by changing the Data file),
thus, keeping it extensible and easily adaptable.

This implementation of a Binary Tree contains Nodes which contain pieces of Data. A Data 
can technically be anything, as long as the Data files are properly configured. The 
current implementation allows a string and a frequency count in a Data, which is used for
frequency counting text documents (ie. bag of words). However, the Data can be altered to
suit the needs of any program that requires a binary tree.

See main.c for a test case.

Test instructions:
- make test  

Which is a combination of these 3 commands (you can use these if the first one doesn't work):
- make
- make run_test
- make clean
