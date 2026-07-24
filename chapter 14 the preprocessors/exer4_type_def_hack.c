/*
 Let GENERIC_MAX be the following macro:
#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{ \
 return x > y ? x : y; \
}
(a) Show the preprocessor’s expansion of GENERIC_MAX(long).
(b) Explain why GENERIC_MAX doesn’t work for basic types such as unsigned long.
(c) Describe a technique that would allow us to use GENERIC_MAX with basic types such
as unsigned long. Hint: Don’t change the definition of GENERIC_MAX.

*** Answer ***
(a) 
long long_max(long x, long y)
{
  return x > y ? x : y;
}

(b)
Because there is whitespace between unsigned long which cut off
the function name "type##_max" into two parts as:
unsigned long unsigned long_max(...);

(c) (From textbook. I didn't figure this out)
To make GENERIC_MAX work with any basic type, use a type definition to rename the type:

typedef unsigned long ULONG;
We can now write GENERIC_MAX(ULONG).
*/

#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{ \
 return x > y ? x : y; \
}

