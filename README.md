strxcpy is a single file library for sized string copying in C23.

How to use:  

Add strxcpy.h to your project.  
#include it  
call the function.

Adding an external entry point:  

By default strxcpy.h provides only an inline definition of strxcpy, in order to provide an extern definition exactly one textual unit must `#define STRXCPY_DEFINE_ENTRY_POINT` before including strxcpy.h

Prototype:
  
`char* strxcpy(char * restrict dst, char const * restrict src, size_t len);`

Parameters:
  * dst -- the string to copy into.
  * src -- the string to copy from.
  * len -- the maximum ammount of characters to copy from src to dst.
  
Result:
  * A pointer to the location in dst of the copied nul character, if present.
  * A nullptr if no nul was copied from source.

dst is always nul-terminated. If no nul is copied, dst[len - 1] will be set to '\0'

No code in this repository was AI generated. Don't ask why I bothered publishing such a trivial library.

TODO: format README
