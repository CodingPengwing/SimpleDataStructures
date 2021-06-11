# Binary Tree #
An implementation of dynamically managed binary trees. 
The creation (memory allocation), insertion, and deletion (free) of the adjacency list
and elements inside the adjacency list are abstracted into functions, hiding the details
of pointer and memory allocation from the user.

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
