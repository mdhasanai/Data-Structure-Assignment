# Data-Structure
#Task:

For this assignment you are required to write a program which accepts the name of a text file
from the command line. You can assume that the text file contains English text. The program
should then output the frequency of each word in the file, along with a list of position indexes.
The information for each unique word should be shown only once.

If for example the input text file contains the following content:

The quick brown fox jumps over the lazy dog. However, the dog really did not care.

The output should be the following:

T o t a l number o f words : 16

Word f r e q u e n c i e s and p o s i t i o n s :

the − 0 . 1 8 7 5 : 1 ,7 ,11
quick − 0.0625: 2
brown − 0 . 0 6 2 5 : 3
fox − 0.0625: 4
jumps − 0 . 0 6 2 5 : 5
over − 0 . 0 6 2 5 : 6
lazy − 0.0625: 8
dog − 0 . 1 2 5 : 9 , 12
however − 0 . 0 6 2 5 : 10
r e a l l y − 0 . 0 6 2 5 : 13
d i d − 0 . 0 6 2 5 : 14
not − 0 . 0 6 2 5 : 15
c a r e − 0 . 0 6 2 5 : 16


Please note that this example is extremely small. Your program should be written so that it can
handle an arbitrary number of words, appearing in an arbitrary number of positions. You can also
assume that to receive good marks, your program must reliably work with files larger than 1 MB.
