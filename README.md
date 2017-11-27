# ft_printf

A norm-compliant recreation of the C standard library's printf function.
This function is written using only write(), malloc(), and free(), as well as the variable argument macros defined in <stdarg.h>.

It is capable of handling width and precision, as well as these format specifiers:

%s - string  
%c - char  
%d, %i - integer  
%u - unsigned int  
%x, %X - unsigned int (in hexadecimal)  
%o - unsigned int (in octal)  

These length specifiers:

l = long  
ll = long long  
h = short  
hh = signed char  
j = intmax  
z = size_t  

As well as these flags:

\# = appends a 0, 0x, or 0X in front of an unsigned integer  
0 = appends or pads a number with 0s  
\+ = appends a '+' to positive signed integers  
\- = right-aligns output when specified  
\<space> = appends a space ahead of positive signed integers 
