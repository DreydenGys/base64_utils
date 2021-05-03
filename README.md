# base64_utils
Usefull function for base64 decode/encode.

# How to

You can easily compile the project using the `Makefile` provided in the repo. Make sure you have gcc installed.

You can use the two following functions defined in the base64.h file:
- `base64_encode`: encode the string used as the first parameter and return it as a pointer  
-  `base64_decode`: decode the string used as the second parameter and return it as a pointer  

To use those function just include base64.h in your own code. Don't forget to compile base64.c into base64.o using the makefile provided.
See more details for the function in the files [base64.h](base64.h)
