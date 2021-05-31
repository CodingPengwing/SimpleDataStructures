# C-DataStructures_Core
An attempt to make some beautiful looking reusable/maintainable code for some fundamental Data Structures
in C. 

To test the codes: 
1. Clone the folders 
2. Navigate to each folder in terminal, type "make" to make the files 
3. Type "make run" to run the executable 
4. Type "make clean" to clean up the executables when done (this was written for UNIX, for Windows the 
   executable is named differently and thus it won't clean up properly and will leave the test.exe file, 
   you can just manually delete that)

Feel free to change the main() function in each folder to test to your own liking.
I will add functionality to take input soon.

PS. To unclutter the code, exception handling has been mostly omitted with only a few assert()'s after 
using malloc(). An integration of these libraries into any code should be tweaked to check for more 
errors with the use of exit_with_error() defined within "util.h".
