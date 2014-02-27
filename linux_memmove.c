#if 0
Moves one buffer to another.
void *memmove( 
   void* dest, 
   const void* src, 
size_t count 
);

wchar_t *wmemmove(
   wchar_t* dest, 
   const wchar_t* src, 
   size_t count
);
Parameters
dest
Destination object.
src
Source object.
count
Number of characters to copy.
Return Values

memmove returns the value of dest.
Remarks

The memmove function copies count characters from src to dest. 

If some regions of the source area and the destination overlap, memmove ensures that the original source characters in the overlapping region are copied before being overwritten.

Example
/* MEMCPY.C: Illustrate overlapping copy: memmove
 * handles it correctly; memcpy does not.
 */
#endif
#include <memory.h>
#include <string.h>
#include <stdio.h>

char string1[60] = "The quick brown dog jumps over the lazy fox";
char string2[60] = "The quick brown fox jumps over the lazy dog";
/*                           1         2         3         4         5
 *                  12345678901234567890123456789012345678901234567890
 */

void main( void )
{
   printf( "Function:\tmemcpy without overlap\n" );
   printf( "Source:\t\t%s\n", string1 + 40 );
   printf( "Destination:\t%s\n", string1 + 16 );
   memcpy( string1 + 16, string1 + 40, 3 );
   printf( "Result:\t\t%s\n", string1 );
   printf( "Length:\t\t%d characters\n\n", strlen( string1 ) );

   /* Restore string1 to original contents */
   memcpy( string1 + 16, string2 + 40, 3 );

   printf( "Function:\tmemmove with overlap\n" );
   printf( "Source:\t\t%s\n", string2 + 4 );
   printf( "Destination:\t%s\n", string2 + 10 );
   memmove( string2 + 10, string2 + 4, 40 );
   printf( "Result:\t\t%s\n", string2 );
   printf( "Length:\t\t%d characters\n\n", strlen( string2 ) );

   printf( "Function:\tmemcpy with overlap\n" );
   printf( "Source:\t\t%s\n", string1 + 4 );
   printf( "Destination:\t%s\n", string1 + 10 );
   memcpy( string1 + 10, string1 + 4, 40 );
   printf( "Result:\t\t%s\n", string1 );
   printf( "Length:\t\t%d characters\n\n", strlen( string1 ) );
}
/*
Output
Function:   memcpy without overlap
Source:      fox
Destination:   dog jumps over the lazy fox
Result:      The quick brown fox jumps over the lazy fox
Length:      43 characters

Function:   memmove with overlap
Source:      quick brown fox jumps over the lazy dog
Destination:   brown fox jumps over the lazy dog
Result:      The quick quick brown fox jumps over the lazy dog
Length:      49 characters

Function:   memcpy with overlap
Source:      quick brown dog jumps over the lazy fox
Destination:   brown dog jumps over the lazy fox
Result:      The quick quick brown dog jumps over the lazy fox
Length:      49 characters
Requirements

OS Versions: Windows CE 2.0 and later.
Header: stdlib.h and wchar_ship.h.
Link Library: coredll.dll.
*/
