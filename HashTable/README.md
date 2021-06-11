# HashTable

This is an implementation of a hash table in C. The table is 
an array comprised of Slot structures which represent the
slots in the hash table. Each of these structures contain a 
Data and a boolean value to determine whether the slot is 
free or occupied. Inside the Datas themselves are strings
that are hashed into the table.

_(Testing instructions at the bottom)_

The program will take input as follows:  
- 1st line: N M K  
- And then N lines of strings  
-> Eg:  
5 10 2  
Hash  
Tables  
Are  
Really  
Cool

Where N is the number of following input, M is the length that 
the table will be initialised to, and K is the amount of slots 
that the hash value will shift by everytime the program fails 
to find a free slot.

The program will return a hash table that will contain all the
given strings in their correct hash positions. The table will
be resized as many times as necessary (doubling each time) in
order to fit all of this data in.

Using test-in-1.txt file, the output will look something like 
this:   
0: Really  
1: Hash  
2:  
3: Cool  
4: Tables  
5:  
6:  
7:  
8: Are  
9:  

_(Check the tests files for more examples)_

Test instructions:
- make test  

Which is a combination of these 3 commands (you can use these if the first one doesn't work):
- make
- make run_test
- make clean
